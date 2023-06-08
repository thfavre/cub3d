#include "mlx.h"
#include "vector2.h"
#include "data.h"
#include "events.h"

int		on_update(t_data *data);
int		on_close(t_data *data);
void	keys_init(bool *key_pressed);
int		on_keypressed(int keycode, bool *key_pressed);
int		on_keyreleased(int keycode, bool *key_pressed);


void	init(t_data data) // TODO how to name it?
{
	data.mlx = mlx_init(); // test is null
	data.img.size = (t_vector2){1920, 1080};
	data.win = mlx_new_window(data.mlx, data.img.size.x, data.img.size.y,
		"Hello World!");
	data.img.img = mlx_new_image(data.mlx, data.img.size.x, data.img.size.y);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp,
		&data.img.line_len, &data.img.endian);
	keys_init(data.key_pressed);
	mlx_hook(data.win, KeyPress, KeyPressMask, on_keypressed, &data.key_pressed);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, on_keyreleased, &data.key_pressed);
	data.mouse_pos = (t_vector2){0, 0};
	mlx_hook(data.win, DestroyNotify, NoEventMask, on_close, &data); // add a struct to pass the engine and the user callback?
	mlx_loop_hook(data.mlx, on_update, &data);
	mlx_loop(data.mlx);
}
