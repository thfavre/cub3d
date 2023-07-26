/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _time.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:16:15 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:25:54 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mlx.h"
#include "libft.h"
#include "draw.h"
#include <time.h>

double	get_delta_time(void)
{
	double			current_time;
	double			delta_time;
	static double	previous_time = 0;

	current_time = (double)clock() / CLOCKS_PER_SEC;
	delta_time = current_time - previous_time;
	previous_time = current_time;
	return (delta_time);
}

int	get_avrage_fps(float dt)
{
	static int		frames = 0;
	static float	elapsed_time = 0;
	static int		avrage_fps = 0;

	frames++;
	elapsed_time += dt;
	if (elapsed_time >= 0.2)
	{
		avrage_fps = frames / elapsed_time;
		frames = 0;
		elapsed_time = 0;
	}
	return (avrage_fps);
}

void	draw_fps(t_data *data)
{
	char	*fps_str;
	char	*str;
	int		avrage_fps;

	avrage_fps = get_avrage_fps(data->dt);
	fps_str = ft_itoa(avrage_fps);
	if (!fps_str)
		return ;
	str = ft_strjoin("FPS: ", fps_str);
	free(fps_str);
	if (!str)
		return ;
	mlx_string_put(data->mlx, data->win, 5, 15, C_WHITE, str);
	free(str);
}
