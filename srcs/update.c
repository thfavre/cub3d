#include "data.h"
#include "keycodes.h"
#include "draw.h"
#include "time_utils.h"
#include <stdio.h>

void on_update_utils(t_data *data); // Put the function in update.c?

int on_update(t_data *data)
{
	draw_background(&data->img, COLOR_GOLD3);

	get_avrage_fps(data->dt);

	on_update_utils(data);
}

