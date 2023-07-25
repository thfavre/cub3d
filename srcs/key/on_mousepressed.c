#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_mousepressed(int mousecode, int x, int y, t_data *data)
{
	data->mouse_just_pressed = true;
	data->mouse_pressed = true;
	return (0);
}
