#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_keypressed(int keycode, t_data *data)
{
	if (keycode < MAX_KEYS)
	{
		data->key_pressed[keycode] = true;
		data->key_just_pressed[keycode] = true;
	}
	return (0);
}
