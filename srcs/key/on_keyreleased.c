#include <stdbool.h>
#include "keycodes.h"

int	on_keyreleased(int keycode, bool *key_pressed)
{
	if (keycode < MAX_KEYS && key_pressed[keycode])
		key_pressed[keycode] = false;
	return (0);
}