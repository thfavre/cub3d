#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_mousepressed(int keycode, t_data *data)
{
	// printf("Key pressed: %d\n", data->mouse_just_pressed);
	printf("Mouse pressed: %d\n", keycode);
	return (0);
}
