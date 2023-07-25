#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_mouserelease(int mousecode, int x, int y, t_data *data)
{
	data->mouse_pressed = false;
	return (0);
}
