#include <stdio.h>

#include "data.h"
#include "keycodes.h"
#include "draw.h"
#include "game2d.h"
#include "mlx.h"

void on_update_utils(t_data *data); // Put the function in update.c?
int	get_avrage_fps(float dt);

int on_update(t_data *data)
{
	static bool in_menu;
	draw_background(&data->img, data->textures.F);

	// hide mouse when on window
	// if (data->mouse_pos.x >= 0 && data->mouse_pos.x < SCREEN_WIDTH && \
	// 	data->mouse_pos.y >= 0 && data->mouse_pos.y < SCREEN_HEIGHT)
	// 	mlx_mouse_hide(data->mlx, data->win);
	// else
	// 	mlx_mouse_show(data->mlx, data->win);

	// mouse center screen
	if (!in_menu)
		mlx_mouse_move(data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	if (data->key_just_pressed[K_SPACE])
	{
		in_menu = !in_menu;
		if (in_menu)
			printf("In menu\n");
	}
	draw_minimap(data, data->map, data->game.minimap);
	update_player(data, &data->game);

	get_avrage_fps(data->dt);

	on_update_utils(data);
}

