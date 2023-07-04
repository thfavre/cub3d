#include "data.h"

void	register_player(t_data *data, t_game2d *game2d);
bool	register_walls(t_data *data);
int		count_walls(t_data *data);
void	register_angle(t_game2d *game2d, char c);

void	init_settings(t_data *data)
{
	data->game2d.size_block = (t_vector2){50, 50};
	data->game2d.minimap.offset = (t_vector2){MINIMAP_OFFSET, MINIMAP_OFFSET};
	data->game2d.minimap.size = (t_vector2){SCREEN_WIDTH / 4,
		SCREEN_HEIGHT / 4};
	if (data->game2d.minimap.size.x / data->map_size.x
		> data->game2d.minimap.size.y / data->map_size.y)
		data->game2d.minimap.scale = (data->game2d.minimap.size.y
				/ data->map_size.y) / (float)data->game2d.size_block.y;
	else
		data->game2d.minimap.scale = (data->game2d.minimap.size.x
				/ data->map_size.x) / (float)data->game2d.size_block.x;
	data->game2d.player.speed = 100;
	data->game2d.player.size = (t_vector2){data->game2d.size_block.x * 0.8,
		data->game2d.size_block.y * 0.8};
	register_player(data, &data->game2d);
	register_walls(data);
}

void	register_player(t_data *data, t_game2d *game2d)
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
				game2d->player.pos = (t_fvector2){(x * game2d->size_block.x),
					(y * game2d->size_block.y)};
				register_angle(game2d, data->map[y][x]);
				break ;
			}
		}
	}
}

bool	register_walls(t_data *data)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	data->game2d.walls_count = count_walls(data);
	data->game2d.walls = ft_calloc(data->game2d.walls_count + 1,
			sizeof(t_wall));
	if (!data->game2d.walls)
		return (false);
	y = -1;
	i = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1')
			{
				data->game2d.walls[++i].rect = (t_rect){x
					* data->game2d.size_block.x, y * data->game2d.size_block.y,
					data->game2d.size_block.x, data->game2d.size_block.y};
			}
		}
	}
}

int	count_walls(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
			if (data->map[y][x] == '1')
				i++;
	}
	return (i);
}

void	register_angle(t_game2d *game2d, char c)
{
	if (c == 'N')
		game2d->minimap.angle = M_PI / 2;
	else if (c == 'S')
		game2d->minimap.angle = 3 * M_PI / 2;
	else if (c == 'E')
		game2d->minimap.angle = 0;
	else if (c == 'O')
		game2d->minimap.angle = M_PI;
}
