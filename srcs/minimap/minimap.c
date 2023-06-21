#include "draw.h"
#include "color.h"
#include "game2d.h"

void	draw_minimap(t_data *data, t_game game)
{
	int		x;
	int		y;
	t_rect	current_rect;

	draw_rect(&data->img, (t_rect){game.minimap.offset.x,
		game.minimap.offset.y, game.minimap.size.x,
		game.minimap.size.y}, 0x80808010);
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			current_rect = (t_rect){(x * game.minimap.block)
				+ game.minimap.offset.x, (y * game.minimap.block)
				+ game.minimap.offset.y, game.minimap.block,
				game.minimap.block};
			if (data->map[y][x] == '1')
				draw_rect(&data->img, current_rect, C_BLACK);
			else if (data->map[y][x] == '0' || data->map[y][x] == 'N'
				|| data->map[y][x] == 'S' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'O')
				draw_rect(&data->img, current_rect, C_BLUE);
		}
	}
}
