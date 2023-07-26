/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:55:11 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:22:32 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "rect.h"
#include "color.h"
#include "libft.h"
#include "mlx.h"
#include "draw.h"

bool	update_check_box(t_data *data, t_check_box *check_box)
{
	t_rect	hitbox_rect;
	int		check_box_color;

	hitbox_rect = (t_rect){check_box->pos.x, check_box->pos.y,
		check_box->width, check_box->width};
	if (check_box->checked)
		check_box_color = 0x27ae60;
	else
		check_box_color = 0xc0392b;
	if (collide_point(data->mouse_pos, hitbox_rect))
	{
		if (check_box->checked)
			check_box_color = 0x2ecc71;
		else
			check_box_color = 0xe74c3c;
		if (data->mouse_just_pressed)
			check_box->checked = !check_box->checked;
	}
	draw_rect(&data->img, hitbox_rect, C_BLACK);
	draw_rect(&data->img, (t_rect){check_box->pos.x + 3, check_box->pos.y + 3,
		check_box->width - 6, check_box->width - 6}, check_box_color);
	return (check_box->checked);
}

void	update_check_box_text(t_data *data, t_check_box *check_box)
{
	char	*text;
	int		text_width;
	int		rect_width;
	int		x_pos;

	if (check_box->checked)
		text = ft_strjoin(check_box->text, "ON");
	else
		text = ft_strjoin(check_box->text, "OFF");
	if (!text)
		return ;
	text_width = ft_strlen(text) * 5.85;
	rect_width = text_width + 10;
	x_pos = check_box->pos.x + check_box->width / 2 - text_width / 2;
	draw_rect(&data->img, (t_rect){x_pos + text_width / 2 - rect_width / 2,
		check_box->pos.y - 20, rect_width, 15}, C_WHITE);
	mlx_string_put(data->mlx, data->win, x_pos,
		check_box->pos.y - 9, C_BLACK, text);
	free(text);
}
