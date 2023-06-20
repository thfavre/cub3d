#include "data.h"
#include "keycodes.h"
#include "draw.h"
#include "time_utils.h"
#include <stdio.h>

void on_update_utils(t_data *data); // Put the function in update.c?

int on_update(t_data *data)
{
	draw_background(&data->img, data->textures.F);

	// draw the walls (to put in a function)
	int i = 0;
	while (i < data->game.obstacles.number)
		draw_rect(&data->img, data->game.obstacles.rects[i++], C_BLACK);


	update_player(&data->img, data->key_pressed, &data->game.player, data->game.obstacles, data->dt);

	get_avrage_fps(data->dt);

	on_update_utils(data);
}

