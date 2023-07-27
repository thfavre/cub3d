/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:26:29 by thfavre           #+#    #+#             */
/*   Updated: 2023/07/27 12:29:15 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

typedef struct s_settings_sliders
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
}	t_settings_sliders;

typedef struct s_settings_check_boxes
{
	t_check_box	settings_box;
	t_check_box	textured_box;
	t_check_box	reset_box;
}	t_settings_check_boxes;

typedef struct s_settings_gui
{
	t_settings_sliders		*sliders;
	t_settings_check_boxes	*check_boxes;
}	t_settings_gui;

t_settings_gui	*update_settings(t_data *data);
void			update_settings_text(t_data *data,
					t_settings_gui *settings_gui);

#endif
