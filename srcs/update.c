#include "data.h"
#include "keycodes.h"
#include "draw.h"
#include "time_utils.h"
#include <stdio.h>

void on_update_utils(t_data *data); // Put the function in update.c?

float RECT_SIZE = 100;
RECT_DIRECTION = -1;
LINES_SPACING = 60;
MOVING = 0;
MOVING2 = 0;

int on_update(t_data *data)
{
	draw_background(&data->img, COLOR_GOLD3);

	printf("FPS : %d\n", get_avrage_fps(data->dt));

	on_update_utils(data);
}

