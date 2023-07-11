#include "data.h"
#include "game2d.h"

float	raycasting_up(t_data *data, t_ray ray, float scale);
float	raycasting_down(t_data *data, t_ray ray, float scale);
float raycasting_right(t_data *data, t_ray ray, float scale);
char	get_tile_type_from_pos(char **map, t_vector2 size_block, t_vector2 pos);

void	raycasting(t_data *data, t_player *player, t_minimap *minimap)
{
	t_ray	ray;
	float	vertical_ray;
	float	horizontal_ray;
	int		i;

	ray.player_center = (t_vector2){player->pos.x + player->size.x / 2,
		player->pos.y + player->size.x / 2};
	ray.angle_increment = FOV_RAD / (NB_RAYS - 1);
	i = -1;
	while (++i < NB_RAYS)
	{
		ray.ray_angle = player->angle - FOV_RAD / 2 + (i * ray.angle_increment);
		if (ray.ray_angle < M_PI && ray.ray_angle >= 0 && ray.ray_angle != M_PI)
			vertical_ray = raycasting_up(data, ray, minimap->scale);
		else
			vertical_ray = raycasting_down(data, ray, minimap->scale);
		if (ray.ray_angle < M_PI / 2 && ray.ray_angle >= 3 * M_PI / 2)
			horizontal_ray = raycasting_right(data, ray, minimap->scale);
	}
}

float	raycasting_up(t_data *data, t_ray ray, float scale) // valeur de retour avec pythagore
{
	int	i;

	i = 0;
	ray.ray_pos = ray.player_center;
	ray.side.y = ray.ray_pos.y % data->game2d.size_block.y;
	ray.side.x = 1 - (int)(tan(ray.ray_angle - M_PI / 2) * ray.side.y);
	ray.ray_pos.x += ray.side.x;
	ray.ray_pos.y -= ray.side.y;
	ray.delta.y = data->game2d.size_block.y;
	ray.delta.x = 1 - tan(ray.ray_angle - M_PI / 2) * ray.delta.y;
	while (true)
	{
		if (get_tile_type_from_pos(data->map, data->game2d.size_block,
				(t_vector2){ray.ray_pos.x + i * ray.delta.x, ray.ray_pos.y
				- i * ray.delta.y - 1}) == '1')
			break ;
		i++;
	}
		ray.ray_pos.x += i * ray.delta.x;
		ray.ray_pos.y -= i * ray.delta.y;
	draw_line(&data->img, (t_vector2){ray.player_center.x * scale
		+ MINIMAP_OFFSET, ray.player_center.y * scale + MINIMAP_OFFSET},
		(t_vector2){(ray.ray_pos.x) * scale + MINIMAP_OFFSET, (ray.ray_pos.y)
		* scale + MINIMAP_OFFSET}, C_RED, 1);
}

float	raycasting_down(t_data *data, t_ray ray, float scale)
{
	int	i;

	i = 0;
	ray.ray_pos = ray.player_center;
	ray.side.y = data->game2d.size_block.y - (ray.ray_pos.y % data->game2d.size_block.y);
	ray.side.x = (int)(tan(ray.ray_angle - M_PI / 2) * ray.side.y);
	ray.ray_pos.x += ray.side.x;
	ray.ray_pos.y += ray.side.y;
	ray.delta.y = data->game2d.size_block.y;
	ray.delta.x = tan(ray.ray_angle - M_PI / 2) * ray.delta.y;
	while (true)
	{
		if (get_tile_type_from_pos(data->map, data->game2d.size_block,
				(t_vector2){ray.ray_pos.x + i * ray.delta.x, ray.ray_pos.y
				+ i * ray.delta.y}) == '1')
			break ;
		i++;
	}
	ray.ray_pos.x += i * ray.delta.x;
	ray.ray_pos.y += i * ray.delta.y;
	draw_line(&data->img, (t_vector2){ray.player_center.x * scale
		+ MINIMAP_OFFSET, ray.player_center.y * scale + MINIMAP_OFFSET},
		(t_vector2){ray.ray_pos.x * scale + MINIMAP_OFFSET, ray.ray_pos.y
		* scale + MINIMAP_OFFSET}, C_RED, 1);
}

float raycasting_right(t_data *data, t_ray ray, float scale)
{
	int	i;

	i = 0;
	ray.ray_pos = ray.player_center;
	ray.side.x = data->game2d.size_block.x - (ray.ray_pos.x % data->game2d.size_block.x);
	ray.side.y = (int)(tan(ray.ray_angle) * ray.side.x);
	ray.ray_pos.x += ray.side.x;
	ray.ray_pos.y += ray.side.y;
	ray.delta.x = data->game2d.size_block.x;
	ray.delta.y = tan(ray.ray_angle) * ray.delta.x;
	while (true)
	{
		if (get_tile_type_from_pos(data->map, data->game2d.size_block,
				(t_vector2){ray.ray_pos.x + i * ray.delta.x, ray.ray_pos.y + i * ray.delta.y}) == '1')
				break ;
		i++;
	}
	ray.ray_pos.x += i * ray.delta.x;
	ray.ray_pos.y += i * ray.delta.y;
	draw_line(&data->img, (t_vector2){ray.player_center.x * scale
		+ MINIMAP_OFFSET, ray.player_center.y * scale + MINIMAP_OFFSET},
		(t_vector2){ray.ray_pos.x * scale + MINIMAP_OFFSET, ray.ray_pos.y
		* scale + MINIMAP_OFFSET}, C_RED, 1);
}

char	get_tile_type_from_pos(char **map, t_vector2 size_block, t_vector2 pos)
{
	int	x;
	int	y;

	x = (int)pos.x / size_block.x;
	y = (int)pos.y / size_block.y;
	if (x < 0 || y < 0 || y >= 14 || x >= ft_strlen(map[y])) //TODO not hardcode 14, find mapsize
		return ('1');
	return (map[y][x]);
}
