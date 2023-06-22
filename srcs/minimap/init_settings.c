#include "data.h"

void	register_player(t_data *data);

void	init_settings(t_data *data)
{
	data->game.minimap.offset = (t_vector2){MINIMAP_OFFSET, MINIMAP_OFFSET};
	data->game.minimap.size = (t_vector2){SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4};
	if (data->game.minimap.size.x / data->map_size.x
		> data->game.minimap.size.y / data->map_size.y)
		data->game.minimap.block = data->game.minimap.size.y
			/ data->map_size.y;
	else
		data->game.minimap.block = data->game.minimap.size.x
			/ data->map_size.x;
	data->game.player.speed = 100;
	data->game.player.size = data->game.minimap.block * 0.75;
	register_player(data);
}

void	register_player(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'O')
			{
				data->game.player.pos = (t_fvector2){(x
						* data->game.minimap.block),
					(y * data->game.minimap.block)};
				break ;
			}
		}
	}
}
