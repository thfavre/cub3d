#include "data.h"
#include "mlx.h"

int	on_close(t_data *data); // TODO put this in a header file??
double get_elapsed_time(void); // TODO putin header file


void on_update_utils(t_data *data) // TODO rename this function and put in update.c file?
{
	if (data->key_pressed[K_ESC])
		on_close(data);
	data->dt = get_elapsed_time();
	mlx_mouse_get_pos(data->mlx, data->win, &data->mouse_pos.x, &data->mouse_pos.y);
	mlx_put_image_to_window(data->mlx, data->win, \
		data->img.img, 0, 0);
}
