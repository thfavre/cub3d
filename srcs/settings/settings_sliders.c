/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_sliders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:28:06 by thfavre           #+#    #+#             */
/*   Updated: 2023/07/28 13:16:30 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "settings.h"
#include "gui.h"

t_settings_sliders		*init_sliders(void);

t_settings_sliders	*update_sliders(t_data *data)
{
	t_settings_sliders	*sliders;

	sliders = init_sliders();
	if (!data->show_settings)
		return (NULL);
	data->map_mult = update_slider(data, &sliders->map_mult);
	data->fov_deg = update_slider(data, &sliders->fov);
	data->nb_rays = update_slider(data, &sliders->nb_rays);
	data->walls_height = update_slider(data, &sliders->walls_height);
	data->walls_y_offset = update_slider(data, &sliders->walls_y_offset);
	if (!data->textured)
	{
		data->untextured_color = set_color_red_value(data->untextured_color,
				update_slider(data, &sliders->untextured_color_r));
		data->untextured_color = set_color_green_value(data->untextured_color,
				update_slider(data, &sliders->untextured_color_g));
		data->untextured_color = set_color_blue_value(data->untextured_color,
				update_slider(data, &sliders->untextured_color_b));
	}
	data->game2d.player.speed = 50 * update_slider(data,
			&sliders->player_move_speed);
	data->game2d.player.rotate_speed = update_slider(data,
			&sliders->rotate_speed);
	return (sliders);
}

t_settings_sliders	*init_sliders(void)
{
	static t_settings_sliders	sliders = {
	{(t_vector2){40, 325}, 40, 225, 0,
		MINIMAP_SIZE_RATIO, 1, "Minimap scale: "},
	{(t_vector2){40, 400}, 40, 225, -180,
		360, DEFAULT_FOV_DEG, "FOV: "},
	{(t_vector2){40, 475}, 40, 225, 2,
		SCREEN_WIDTH, DEFAULT_NB_RAYS, "Rays nb: "},
	{(t_vector2){40, 550}, 40, 225, 1,
		SCREEN_HEIGHT / 2, DEFAULT_WALLS_HEIGHT, "Walls height: "},
	{(t_vector2){40, 625}, 40, 225,
		-SCREEN_HEIGHT / 1.4, SCREEN_HEIGHT / 1.4, 0, "Walls y offset: "},
	{(t_vector2){100, 715}, 25, 45, 0, 255, 155, "r: "},
	{(t_vector2){185, 715}, 25, 45, 0, 255, 89, "g: "},
	{(t_vector2){270, 715}, 25, 45, 0, 255, 182, "b: "},
	{(t_vector2){40, 775}, 40, 79, 0,
		15, DEFAULT_PLAYER_MOVE_SPEED, "Speed: "},
	{(t_vector2){188, 775}, 40, 77, 0,
		15, DEFAULT_PLAYER_ROTATE_SPEED, "Rotation: "}
	};

	return (&sliders);
}
