#include <stdio.h>

#include "data.h"
#include "keycodes.h"
#include "game2d.h"
#include "mlx.h"
#include <math.h>
#include "libft.h"
#include "draw.h"
#include "_time.h"

int		on_close(t_data *data);
void	on_update_utils(t_data *data);
void	raycasting(t_data *data, t_player *player, t_minimap *minimap);
void	update_settings(t_data *data);

bool	mouse_control(t_data *data) // TODO where to put that?
{
	static bool	is_mouse_controled = false;

	if (data->key_just_pressed[K_E])
	{
		is_mouse_controled = !is_mouse_controled;
		if (is_mouse_controled)
			mlx_mouse_hide(data->mlx, data->win);
		else
			mlx_mouse_show(data->mlx, data->win);
	}
	if (is_mouse_controled)
	{
		if (data->mouse_pos.x != SCREEN_WIDTH / 2)
		{
			data->game2d.player.angle += (data->mouse_pos.x - SCREEN_WIDTH / 2)
				* data->game2d.player.rotate_speed / 8 * data->dt;
			if (data->game2d.player.angle < 0)
				data->game2d.player.angle += M_PI * 2;
			else if (data->game2d.player.angle > M_PI * 2)
				data->game2d.player.angle -= M_PI * 2;
		}
		mlx_mouse_move(data->mlx, data->win, SCREEN_WIDTH / 2,
			SCREEN_HEIGHT / 2);
	}
	return (is_mouse_controled);
}

void	draw_cursor(t_data *data, bool is_mouse_controled) // TODO where to put that?
{
	int	length;
	int	width;
	int	color;
	int	shadow_color;

	if (!is_mouse_controled)
		return ;
	length = 20;
	width = 4;
	color = C_BLACK;
	shadow_color = C_WHITE;
	draw_rect(&data->img, (t_rect){SCREEN_WIDTH / 2 - length / 2,
		SCREEN_HEIGHT / 2 - width / 2 - 1, length, width}, shadow_color);
	draw_rect(&data->img, (t_rect){SCREEN_WIDTH / 2 - width / 2 -1,
		SCREEN_HEIGHT / 2 - length / 2 - 1, width, length}, shadow_color);
	draw_rect(&data->img, (t_rect){SCREEN_WIDTH / 2 - length / 2,
		SCREEN_HEIGHT / 2 - width / 2, length, width}, color);
	draw_rect(&data->img, (t_rect){SCREEN_WIDTH / 2 - width / 2,
		SCREEN_HEIGHT / 2 - length / 2, width, length}, color);
}

int	on_update(t_data *data)
{
	bool	is_mouse_controled;

	draw_rect(&data->img, (t_rect){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2
		+ data->walls_y_offset}, data->textures.celling);
	draw_rect(&data->img, (t_rect){0, SCREEN_HEIGHT / 2 + data->walls_y_offset,
		SCREEN_WIDTH, SCREEN_HEIGHT / 2 - data->walls_y_offset},
		data->textures.floor);
	is_mouse_controled = mouse_control(data);
	update_player(data, &data->game2d.player);
	raycasting(data, &data->game2d.player, &data->game2d.minimap);
	if (data->game2d.size_block.x * data->game2d.minimap.scale
		* data->map_mult > 3)
		draw_minimap(data, data->map, data->game2d.minimap);
	free(data->rays);
	draw_cursor(data, is_mouse_controled);
	on_update_utils(data);
	update_settings(data);
	data->mouse_just_pressed = false;
	return (0);
}

void	on_update_utils(t_data *data) // put in on_update function?
{
	if (data->key_pressed[K_ESC])
		on_close(data);
	data->dt = get_delta_time();
	mlx_mouse_get_pos(data->mlx, data->win, &data->mouse_pos.x,
		&data->mouse_pos.y);
	mlx_put_image_to_window(data->mlx, data->win, \
		data->img.img, 0, 0);
	ft_bzero(data->key_just_pressed, MAX_KEYS);
	draw_fps(data);
}
