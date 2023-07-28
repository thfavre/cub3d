/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:54:55 by thomas            #+#    #+#             */
/*   Updated: 2023/07/28 13:11:37 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "rect.h"
#include "color.h"
#include "libft.h"
#include "mlx.h"
#include "draw.h"

void	update_slider_text_box(t_data *data, t_slider *slider);

// Easing function to smooth the slider movement
float	smooth_in_out_quad(float t)
{
	return (t * t * (3 - 2 * t));
}

float	update_slider(t_data *data, t_slider *s)
{
	t_rect	box;
	int		slider_color;
	float	fraction;

	slider_color = 0x27ae60;
	box = (t_rect){s->pos.x, s->pos.y, s->length, s->width};
	if (collide_point(data->mouse_pos, box))
	{
		slider_color = 0x2ecc71;
		fraction = smooth_in_out_quad((data->mouse_pos.x - s->pos.x)
				/ (float)s->length);
		if (data->mouse_pressed)
			s->value = s->min_value
				+ fraction * (s->max_value - s->min_value);
	}
	draw_rect(&data->img, (t_rect){s->pos.x, s->pos.y
		+ s->width / 2 - 6 / 2, s->length, 6}, C_BLACK);
	box = (t_rect){s->pos.x + (s->value - s->min_value)
		* s->length / (s->max_value - s->min_value)
		- s->width / 2, s->pos.y, s->width, s->width};
	draw_rect(&data->img, box, C_BLACK);
	draw_rect(&data->img, (t_rect){box.pos.x + 3, box.pos.y + 3,
		box.size.x - 6, box.size.y - 6}, slider_color);
	update_slider_text_box(data, s);
	return (s->value);
}

// platfrom dependant letter width
#if defined(__APPLE__) && defined(__MACH__)
# define LETTER_WIDTH 7
#else
# define LETTER_WIDTH 5.85
#endif

void	update_slider_text(t_data *data, t_slider *slider)
{
	char	*text_value;
	char	*text;
	int		text_width;
	int		x_pos;
	int		rect_width;

	text_value = ft_itoa((int)slider->value);
	if (!text_value)
		return ;
	text = ft_strjoin(slider->text, text_value);
	free(text_value);
	if (!text)
		return ;
	text_width = ft_strlen(text) * LETTER_WIDTH;
	x_pos = slider->pos.x + slider->length * (slider->value
			- slider->min_value)
		/ (slider->max_value - slider->min_value) - text_width / 2;
	rect_width = text_width + 10;
	draw_rect(&data->img, (t_rect){x_pos + text_width / 2 - rect_width / 2,
		slider->pos.y - 20, rect_width, 15}, C_WHITE);
	mlx_string_put(data->mlx, data->win, x_pos, slider->pos.y - 9,
		C_BLACK, text);
	free(text);
}

void	update_slider_text_box(t_data *data, t_slider *slider)
{
	char	*text_value;
	char	*text;
	int		text_width;
	int		x_pos;
	int		rect_width;

	text_value = ft_itoa((int)slider->value);
	if (!text_value)
		return ;
	text = ft_strjoin(slider->text, text_value);
	free(text_value);
	if (!text)
		return ;
	text_width = ft_strlen(text) * LETTER_WIDTH;
	x_pos = slider->pos.x + slider->length * (slider->value
			- slider->min_value)
		/ (slider->max_value - slider->min_value) - text_width / 2;
	rect_width = text_width + 10;
	draw_rect(&data->img, (t_rect){x_pos + text_width / 2 - rect_width / 2,
		slider->pos.y - 20, rect_width, 15}, C_WHITE);
	free(text);
}
