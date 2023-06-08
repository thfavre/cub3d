#include "data.h"
#include "keycodes.h"
#include "draw.h"
#include <stdio.h>

int	on_close(t_data *data); // TODO put this in a header file??
void tmp(t_data *data);
int	get_avrage_fps(float dt); // TODO putin header file
double get_elapsed_time(); // TODO putin header file

int on_update(t_data *data)
{
	tmp(data);
	if (data->key_pressed[K_ESC])
		on_close(data);
	if (data->key_pressed[K_R]) // erase the screen
		draw_background(&data->img, COLOR_BLACK);

	if (data->key_pressed[K_SPACE])
		draw_rect(&data->img, (t_rect){data->mouse_pos.x, data->mouse_pos.y, 32, 32}, COLOR_BLUEVIOLET);
	printf("FPS : %d\n", get_avrage_fps(data->dt));
}

void tmp(t_data *data) // TODO rename this function
{
	data->dt = get_elapsed_time();
	// #if __APPLE__
		mlx_mouse_get_pos(data->win, &data->mouse_pos.x, &data->mouse_pos.y);
	// # else
		// mlx_mouse_get_pos(engine->mlx, engine->win, &engine->mouse_pos.x, &engine->mouse_pos.y);
	// #endif
	mlx_put_image_to_window(data->mlx, data->win, \
		data->img.img, 0, 0);

}
