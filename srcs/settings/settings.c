/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:34:44 by thomas            #+#    #+#             */
/*   Updated: 2023/07/27 15:06:21 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "settings.h"
#include "gui.h"

t_settings_sliders		*update_sliders(t_data *data);
t_settings_check_boxes	*update_check_boxes(t_data *data,
							t_settings_sliders *sliders);
t_settings_sliders		*init_sliders(void);
void					update_slider_text(t_data *data, t_slider *slider);

t_settings_gui	*update_settings(t_data *data)
{
	t_settings_gui	*settings_gui;

	settings_gui = (t_settings_gui *)malloc(sizeof(t_settings_gui));
	if (!settings_gui)
		return (NULL);
	settings_gui->sliders = init_sliders();
	settings_gui->check_boxes = update_check_boxes(data, settings_gui->sliders);
	update_sliders(data);
	return (settings_gui);
}

void	update_settings_text(t_data *data, t_settings_gui *settings_gui)
{
	t_settings_sliders		*sliders;

	if (!settings_gui)
		return ;
	sliders = settings_gui->sliders;
	update_check_box_text(data, &settings_gui->check_boxes->settings_box);
	if (!data->show_settings)
		return (free(settings_gui));
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
	update_slider_text(data, &sliders->map_mult);
	update_slider_text(data, &sliders->rotate_speed);
	update_check_box_text(data, &settings_gui->check_boxes->textured_box);
	update_check_box_text(data, &settings_gui->check_boxes->reset_box);
	free(settings_gui);
}
