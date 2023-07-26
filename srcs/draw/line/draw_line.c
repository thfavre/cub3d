/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:55:31 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:22:34 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "vector2.h"
#include "image.h"
#include "draw.h"

typedef struct s_delta_step_error {
	t_vector2	delta;
	t_vector2	step;
	int			err;
}				t_delta_step_error;

void	draw_line_step(t_img *img, t_vector2 *pos,
						t_delta_step_error *delta_step_error, int color)
{
	int	err2;

	draw_pixel(img, *pos, color);
	err2 = 2 * delta_step_error->err;
	if (err2 > -delta_step_error->delta.y)
	{
		delta_step_error->err -= delta_step_error->delta.y;
		pos->x += delta_step_error->step.x;
	}
	if (err2 < delta_step_error->delta.x)
	{
		delta_step_error->err += delta_step_error->delta.x;
		pos->y += delta_step_error->step.y;
	}
}

void	draw_line(t_img *img, t_vector2 start_pos, t_vector2 end_pos, int color)
{
	t_delta_step_error	delta_step_error;
	t_vector2			pos;

	delta_step_error.delta = (t_vector2){abs(end_pos.x - start_pos.x),
		abs(end_pos.y - start_pos.y)};
	if (start_pos.x < end_pos.x)
		delta_step_error.step.x = 1;
	else
		delta_step_error.step.x = -1;
	if (start_pos.y < end_pos.y)
		delta_step_error.step.y = 1;
	else
		delta_step_error.step.y = -1;
	pos = start_pos;
	delta_step_error.err = delta_step_error.delta.x - delta_step_error.delta.y;
	while (true)
	{
		draw_line_step(img, &pos, &delta_step_error, color);
		if (pos.x == end_pos.x && pos.y == end_pos.y)
			break ;
	}
}
