#include "data.h"

void	draw_textureless_walls(t_data *data, int wall_height, int color)
{
	static int	i = SCREEN_WIDTH;
	int			draw_start;
	int			draw_end;

	if (wall_height > SCREEN_HEIGHT)
		wall_height = SCREEN_HEIGHT;
	draw_start = -wall_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = wall_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	draw_line(&data->img, (t_vector2){i, draw_start}, (t_vector2){i, draw_end},
		color);
	i--;
	if (i == 0)
		i = SCREEN_WIDTH;
}
