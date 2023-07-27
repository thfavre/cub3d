/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfavre <thfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:27:57 by thomas            #+#    #+#             */
/*   Updated: 2023/07/27 12:45:15 by thfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "vector2.h"
#include "data.h"
#include "events.h"
#include "draw.h"

int		on_update(t_data *data);
int		on_close(t_data *data);
void	keys_init(bool *key_pressed, bool *key_just_pressed,
			bool *mouse_just_pressed);
int		on_keypressed(int keycode, t_data *data);
int		on_keyreleased(int keycode, t_data *data);
int		on_mousepressed(int mousecode, int x, int y, t_data *data);
int		on_mouserelease(int mousecode, int x, int y, t_data *data);

bool	init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (false);
	data->img.size = (t_vector2){SCREEN_WIDTH, SCREEN_HEIGHT};
	data->win = mlx_new_window(data->mlx, data->img.size.x, data->img.size.y, "\
Cub3D");
	if (data->win == NULL)
		return (false);
	data->img.img = mlx_new_image(data->mlx, data->img.size.x,
			data->img.size.y);
	if (data->img.img == NULL)
		return (false);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_do_key_autorepeatoff(data->mlx);
	keys_init(data->key_pressed, data->key_just_pressed,
		&data->mouse_just_pressed);
	mlx_hook(data->win, KEY_PRESS, KEY_PRESS_MASK, on_keypressed, data);
	mlx_hook(data->win, KEY_RELEASE, KEY_RELEASE_MASK, on_keyreleased, data);
	mlx_hook(data->win, BUTTON_PRESS, BUTTON_PRESS_MASK, on_mousepressed, data);
	mlx_hook(data->win, BUTTON_RELEASE, BUTTON_RELEASE_MASK, on_mouserelease,
		data);
	data->mouse_pos = (t_vector2){0, 0};
	mlx_hook(data->win, DESTROY_NOTIFY, NO_EVENT_MASK, on_close, data);
	mlx_loop_hook(data->mlx, on_update, data);
	return (true);
}
