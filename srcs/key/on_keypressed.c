#include <stdbool.h>
#include "keycodes.h"

int	on_keypressed(int keycode, bool *key_pressed)
{
	// printf("Key pressed: %d\n", keycode);
	if (keycode < MAX_KEYS)
		key_pressed[keycode] = true;
	return (0);
}
