/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:15:45 by thomas            #+#    #+#             */
/*   Updated: 2023/07/27 11:02:29 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include <stdbool.h>
# include "vector2.h"
# include "rect.h"

typedef struct s_slider
{
	t_vector2	pos;
	int			width;
	int			length;
	float		min_value;
	float		max_value;
	float		value;
	char		*text;
}				t_slider;

typedef struct s_check_box
{
	t_vector2	pos;
	int			width;
	bool		checked;
	char		*text;
}				t_check_box;

typedef struct s_data	t_data;

bool	collide_point(t_vector2 point, t_rect rect);
float	update_slider(t_data *data, t_slider *slider);
void	update_slider_text(t_data *data, t_slider *slider);
bool	update_check_box(t_data *data, t_check_box *check_box);
void	update_check_box_text(t_data *data, t_check_box *check_box);

#endif
