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
	draw_background(&data->img, COLOR_WHEAT2);
	// TEST
	for (int x=0; x < data->img.size.x; x+=RECT_SIZE)
		for (int y=0; y < data->img.size.y; y+=RECT_SIZE)
			draw_rect(&data->img, (t_rect){(t_vector2){x, y}, (t_vector2){RECT_SIZE, RECT_SIZE}}, add_color(COLOR_BLACK, rgb(x/2, y/1, x/12-y/4)+MOVING));
	MOVING++;
	RECT_SIZE += RECT_DIRECTION* 0.1;
	if (RECT_SIZE > 200 || RECT_SIZE < 5)
		RECT_DIRECTION *= -1;
	for (int y=0; y<=data->img.size.y; y+=LINES_SPACING)
	{
		draw_line(&data->img, (t_vector2){0, (MOVING2/2+y)%data->img.size.y}, (t_vector2){data->mouse_pos.x, data->mouse_pos.y}, COLOR_BLACK,1);
		draw_line(&data->img, (t_vector2){data->img.size.x, data->img.size.y-(MOVING2/2+y)%data->img.size.y}, (t_vector2){data->mouse_pos.x, data->mouse_pos.y}, COLOR_BLACK,1);
	}
	for (int x=0; x<=data->img.size.x; x+=LINES_SPACING)
	{
		draw_line(&data->img, (t_vector2){data->img.size.x-(MOVING2/2+x)%data->img.size.x, 0}, (t_vector2){data->mouse_pos.x, data->mouse_pos.y}, COLOR_BLACK,1);
		draw_line(&data->img, (t_vector2){(MOVING2/2+x)%data->img.size.x, data->img.size.y}, (t_vector2){data->mouse_pos.x, data->mouse_pos.y}, COLOR_BLACK,1);
	}
	MOVING2+=6;
	printf("FPS : %d\n", get_avrage_fps(data->dt));

	on_update_utils(data);
}

