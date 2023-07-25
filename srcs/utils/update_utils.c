#include "data.h"
#include "mlx.h"

int		on_close(t_data *data); // TODO put this in a header file?? Not needed I think
double	get_delta_time(void); // TODO putin header file ?
int		get_avrage_fps(float dt);
void	draw_fps(t_data *data);


void on_update_utils(t_data *data) // TODO rename this function and put in update.c file?
{
	char *str;

	if (data->key_pressed[K_ESC])
		on_close(data);
	data->dt = get_delta_time();
	mlx_mouse_get_pos(data->mlx, data->win, &data->mouse_pos.x, &data->mouse_pos.y);
	mlx_put_image_to_window(data->mlx, data->win, \
		data->img.img, 0, 0);
	ft_bzero(data->key_just_pressed, MAX_KEYS);

	data->mouse_just_pressed = false;
	draw_fps(data);
}
