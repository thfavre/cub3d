#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_keyreleased(int keycode, t_data *data)
{
	if (keycode < MAX_KEYS && data->key_pressed[keycode])
		data->key_pressed[keycode] = false;
	return (0);
}
