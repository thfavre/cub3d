#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_keypressed(int keycode, t_data *data)
{
	// static bool	first_time = true;
	// printf("Key pressed: %d\n", keycode);
	if (keycode < MAX_KEYS)
	{
		data->key_pressed[keycode] = true;
		data->key_just_pressed[keycode] = true;
	}
	return (0);
}
