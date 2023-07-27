/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_check_boxes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:28:16 by thfavre           #+#    #+#             */
/*   Updated: 2023/07/27 15:42:20 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "settings.h"
#include "gui.h"

t_settings_check_boxes	*init_check_boxes(void);

t_settings_check_boxes	*update_check_boxes(t_data *data,
							t_settings_sliders *sliders)
{
	t_settings_check_boxes	*check_boxes;

	check_boxes = init_check_boxes();
	data->show_settings = update_check_box(data, &check_boxes->settings_box);
	if (!data->show_settings)
		return (check_boxes);
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
	return (check_boxes);
}

t_settings_check_boxes	*init_check_boxes(void)
{
	static t_settings_check_boxes	check_boxes = {
	{(t_vector2){40, 250}, 40, true, "Settings: "},
	{(t_vector2){40, 700}, 40, true, "Textures: "},
	{(t_vector2){40, SCREEN_HEIGHT - 60}, 40, false, "Reset: "}
	};

	return (&check_boxes);
}
