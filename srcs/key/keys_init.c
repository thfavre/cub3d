#include <stdbool.h>
#include "keycodes.h"
#include "libft.h"
/*
 * Initializes the key_pressed array by setting all elements to false
 *
 * @param key_pressed: pointer to the boolean array representing key states
*/
void	keys_init(bool *key_pressed, bool *key_just_pressed)
{
	ft_bzero(key_pressed, MAX_KEYS);
	ft_bzero(key_just_pressed, MAX_KEYS);
}
