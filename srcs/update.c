#include <stdio.h>

#include "data.h"
#include "keycodes.h"
#include "draw.h"
#include "game2d.h"
#include "mlx.h"

void on_update_utils(t_data *data); // Put the function in update.c?
int	get_avrage_fps(float dt);

# include <math.h>
# include "libft.h"
# include "draw.h"

void	raycasting(t_data *data, t_player *player, t_minimap *minimap);

int on_update(t_data *data)
{
	static bool in_menu;
	// draw_background(&data->img, data->textures.F);
	draw_rect(&data->img, (t_rect){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2}, data->textures.C);
	draw_rect(&data->img, (t_rect){0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2}, data->textures.F);

	// To make drop the frame rate
	if (data->key_pressed[K_T])
	{
		for (int y = 500; y < SCREEN_HEIGHT; y++)
			for (int x = 0; x < SCREEN_WIDTH; x++)
			{
				for (int i = 0; i < 3; i++)
					draw_rect(&data->img, (t_rect){x, y, 4, 4}, C_WHEAT1);
			}
	}


	// hide mouse when on window
	// if (data->mouse_pos.x >= 0 && data->mouse_pos.x < SCREEN_WIDTH && \
	// 	data->mouse_pos.y >= 0 && data->mouse_pos.y < SCREEN_HEIGHT)
	// 	mlx_mouse_hide(data->mlx, data->win);
	// else
	// 	mlx_mouse_show(data->mlx, data->win);

	// mouse center screen
	// if (!in_menu)
	// {
	// 	if (data->mouse_pos.x != SCREEN_WIDTH / 2)
	// 	{
	// 		data->game2d.player.angle -= (data->mouse_pos.x - SCREEN_WIDTH / 2) * 0.2 * data->dt;
	// 		if (data->game2d.player.angle < 0)
	// 			data->game2d.player.angle += M_PI * 2;
	// 		else if (data->game2d.player.angle > M_PI * 2)
	// 			data->game2d.player.angle -= M_PI * 2;
	// 	}
	// 	mlx_mouse_move(data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	// }

	if (data->key_just_pressed[K_SPACE])
		data->game2d.minimap.scale += 0.1;



	if (data->key_just_pressed[K_SPACE])
	{
		in_menu = !in_menu;
		if (in_menu)
			printf("In menu\n");
	}
	update_player(data, &data->game2d.player);
	raycasting(data, &data->game2d.player, &data->game2d.minimap);
	draw_minimap(data, data->map, data->game2d.minimap);
	get_avrage_fps(data->dt);
	on_update_utils(data);
}

