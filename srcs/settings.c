/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:34:44 by thomas            #+#    #+#             */
/*   Updated: 2023/07/27 03:40:13 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

typedef struct s_sliders		t_sliders;
typedef struct s_check_boxes	t_check_boxes;

void			update_check_boxes(t_data *data, t_sliders *sliders);
t_sliders		*init_sliders(void);
t_check_boxes	*init_check_boxes(void);
void			update_check_boxes(t_data *data, t_sliders *sliders);
void			update_sliders_text(t_data *data, t_sliders *sliders);

typedef struct s_sliders
{
	t_slider	map_mult;
	t_slider	fov;
	t_slider	nb_rays;
	t_slider	walls_height;
	t_slider	walls_y_offset;
	t_slider	untextured_color_r;
	t_slider	untextured_color_g;
	t_slider	untextured_color_b;
	t_slider	player_move_speed;
	t_slider	rotate_speed;
}	t_sliders;

void	update_settings(t_data *data)
{
	t_sliders	*sliders;

	sliders = init_sliders();
	update_check_boxes(data, sliders);
	if (!data->show_settings)
		return ;
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
	data->game2d.player.speed = data->game2d.size_block.x
		* update_slider(data, &sliders->player_move_speed);
	data->game2d.player.rotate_speed = update_slider(data,
			&sliders->rotate_speed);
	update_sliders_text(data, sliders);
}

t_sliders	*init_sliders(void)
{
	static t_sliders	sliders = {
	{(t_vector2){40, 325}, 40, 225, 0,
		MINIMAP_SIZE_RATIO, 1, "Minimap scale: "},
	{(t_vector2){40, 400}, 40, 225, -180,
		720, DEFAULT_FOV_DEG, "FOV: "},
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
		10, DEFAULT_PLAYER_ROTATE_SPEED, "Rotation: "}
	};

	return (&sliders);
}

typedef struct s_check_boxes
{
	t_check_box	settings_box;
	t_check_box	textured_box;
	t_check_box	reset_box;
}	t_check_boxes;

t_check_boxes	*init_check_boxes(void)
{
	static t_check_boxes	check_boxes = {
	{(t_vector2){40, 250}, 40, true, "Settings: "},
	{(t_vector2){40, 700}, 40, true, "Textures: "},
	{(t_vector2){40, SCREEN_HEIGHT - 60}, 40, false, "Reset: "}
	};

	return (&check_boxes);
}

void	update_check_boxes(t_data *data, t_sliders *sliders)
{
	t_check_boxes	*check_boxes;

	check_boxes = init_check_boxes();
	data->show_settings = update_check_box(data, &check_boxes->settings_box);
	update_check_box_text(data, &check_boxes->settings_box);
	if (!data->show_settings)
		return ;
	if (update_check_box(data, &check_boxes->reset_box))
	{
		sliders->map_mult.value = 1;
		sliders->fov.value = DEFAULT_FOV_DEG;
		sliders->nb_rays.value = DEFAULT_NB_RAYS;
		sliders->walls_height.value = DEFAULT_WALLS_HEIGHT;
		sliders->walls_y_offset.value = 0;
		check_boxes->textured_box.checked = true;
		sliders->untextured_color_r.value = 155;
		sliders->untextured_color_g.value = 89;
		sliders->untextured_color_b.value = 182;
		check_boxes->reset_box.checked = false;
		sliders->player_move_speed.value = DEFAULT_PLAYER_MOVE_SPEED;
		sliders->rotate_speed.value = DEFAULT_PLAYER_ROTATE_SPEED;
	}
	data->textured = update_check_box(data, &check_boxes->textured_box);
	update_check_box_text(data, &check_boxes->textured_box);
	update_check_box_text(data, &check_boxes->reset_box);
}

void	update_sliders_text(t_data *data, t_sliders *sliders)
{
	update_slider_text(data, &sliders->map_mult);
	update_slider_text(data, &sliders->fov);
	update_slider_text(data, &sliders->nb_rays);
	update_slider_text(data, &sliders->walls_height);
	update_slider_text(data, &sliders->walls_y_offset);
	if (!data->textured)
	{
		update_slider_text(data, &sliders->untextured_color_r);
		update_slider_text(data, &sliders->untextured_color_g);
		update_slider_text(data, &sliders->untextured_color_b);
	}
	update_slider_text(data, &sliders->player_move_speed);
	update_slider_text(data, &sliders->rotate_speed);
}
