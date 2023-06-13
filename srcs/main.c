#include <stdio.h>

#include "data.h"

// map
// BLOCKSIZE = 40;
// map = {
// 	{1, 1, 0, 1, 1},
// 	{1, 0, 0, 1, 1},
// 	{1, 0, 0, 1, 1},
// 	{1, 1, 0, 5, 1}
// }
// -> liste de wall

void	init(t_data data);

int	main()
{
	t_data	data;

	// data->player = (t_player) {
	// 	.rect = (t_rect) {
	// 		.pos = (t_vector2) {10, 10},
	// 		.size = (t_vector2) {40, 40}
	// 	},
	// 	.speed = 5,
	// 	.color = COLOR_RED
	// };
	init(data);
	return (0);
}
