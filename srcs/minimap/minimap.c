#include "draw.h"
#include "color.h"
#include "game2d.h"

void	draw_player(t_data *data, t_player *player, t_minimap *minimap);
void	raycasting(t_data *data, t_player *player, t_minimap *minimap);
float	raycasting_up(t_data *data, t_ray ray, float scale);
char	get_tile_type_from_pos(char **map, t_vector2 size_block, t_vector2 pos);


void	draw_minimap(t_data *data, char **map, t_minimap minimap)
{
	int		x;
	int		y;
	t_rect	current_rect;

	// draw_rect(&data->img, (t_rect){minimap.offset.x,
		// minimap.offset.y, minimap.size.x, minimap.size.y}, 0xDDE6ED);
	// zoom_minimap(data, &minimap);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			current_rect = (t_rect){x * (data->game2d.size_block.x
					* minimap.scale) + minimap.offset.x - 1, y
				* (data->game2d.size_block.y * minimap.scale)
				+ minimap.offset.y - 1, data->game2d.size_block.x
				* minimap.scale - 2, data->game2d.size_block.x * minimap.scale - 2};
			if (map[y][x] == '1')
				draw_rect(&data->img, current_rect, 0x27374D);
			else if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'E' || map[y][x] == 'W')
				draw_rect(&data->img, current_rect, 0xDDE6ED);
		}
	}
	draw_player(data, &data->game2d.player, &data->game2d.minimap);
}

void	draw_player(t_data *data, t_player *player, t_minimap *minimap)
{
	t_rect	current_rect;

	current_rect = (t_rect){player->pos.x * minimap->scale
		+ minimap->offset.x, player->pos.y * minimap->scale
		+ minimap->offset.y, player->size.x * minimap->scale,
		player->size.y * minimap->scale};
	draw_rect(&data->img, current_rect, 0x526D82);
	t_vector2	start_pos = (t_vector2){(player->pos.x + player->size.x / 2) * minimap->scale
		+ minimap->offset.x, (player->pos.y  + player->size.x / 2) * minimap->scale
			+ minimap->offset.y};
	t_vector2	end_pos = (t_vector2){start_pos.x + cos(player->angle) * 50 * minimap->scale, start_pos.y - sin(player->angle) * 50 * minimap->scale};
	draw_line(&data->img, start_pos, end_pos, 0x00ffff, 5 * minimap->scale);
	raycasting(data, player, minimap);
}

void	raycasting(t_data *data, t_player *player, t_minimap *minimap)
{
	t_ray	ray;
	float	vertical_ray;
	int		i;

	ray.player_center = (t_vector2){player->pos.x + player->size.x / 2,
		player->pos.y  + player->size.x / 2};
	ray.angle_increment = FOV_RAD / (NB_RAYS - 1);
	printf("angle increment %f\n", ray.angle_increment * 180 / M_PI);
	i = -1;
	while (++i < NB_RAYS)
	{
		ray.ray_angle = player->angle - FOV_RAD / 2 + (i * ray.angle_increment);
		// printf("This is ray.ray_angle %f\n", ray.ray_angle);
		// printf("this is player angle %f\n", player->angle);
		if (ray.ray_angle < M_PI && ray.ray_angle >= 0 && ray.ray_angle != M_PI)
			vertical_ray = raycasting_up(data, ray, minimap->scale);
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
	while(true)
	{
		if (get_tile_type_from_pos(data->map, data->game2d.size_block,
			(t_vector2){ray.ray_pos.x + i * ray.delta.x, ray.ray_pos.y - i * ray.delta.y - 1}) == '1')
					break;
		i++;
	}
		ray.ray_pos.x += i * ray.delta.x;
		ray.ray_pos.y -= i * ray.delta.y;
	draw_line(&data->img, (t_vector2){ray.player_center.x * scale + MINIMAP_OFFSET, ray.player_center.y * scale + MINIMAP_OFFSET}, (t_vector2){(ray.ray_pos.x) * scale + MINIMAP_OFFSET, (ray.ray_pos.y) * scale + MINIMAP_OFFSET}, C_RED, 1);
}

char	get_tile_type_from_pos(char **map, t_vector2 size_block, t_vector2 pos)
{
	int x = (int)pos.x / size_block.x;
	int y = (int)pos.y / size_block.y;
	if (x < 0 || y < 0 || y >= 14 || x >= ft_strlen(map[y]))//TODO not hardcode 14, find mapsize
		return ('1');
	// printf("x : %d, y : %d ,f y %f\n", x, y, (float)pos.y / (float)size_block.y);
	return (map[y][x]);
}
