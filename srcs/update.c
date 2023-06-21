#include "data.h"
#include "keycodes.h"
#include "draw.h"
#include "time_utils.h"
#include <stdio.h>

void on_update_utils(t_data *data); // Put the function in update.c?

int on_update(t_data *data)
{
	// draw_background(&data->img, COLOR_GOLD3);
	draw_background(&data->img, data->textures.F);

	// int y = 0;
	// int x;
	// int BLOCK_SIZE = 40;
	// while (data->map[y])
	// {
	// 	x = 0;
	// 	while (data->map[y][x])
	// 	{
	// 		if (data->map[y][x] == '1')
	// 			draw_rect(&data->img, (t_rect){x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE}, data->textures.C);
	// 		x++;
	// 	}
	// 	y++;
	// }
	draw_minimap(data);
	get_avrage_fps(data->dt);

	on_update_utils(data);
}

