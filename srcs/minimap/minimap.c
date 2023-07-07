#include "draw.h"
#include "color.h"
#include "game2d.h"

// void	zoom_minimap(t_data *data, t_minimap *minimap);
void	draw_player(t_data *data, t_player *player, t_minimap *minimap);
// void	raycasting(t_data *data, t_player *player, t_minimap *minimap); UNFINISHED

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
					* minimap.scale) + minimap.offset.x, y
				* (data->game2d.size_block.y * minimap.scale)
				+ minimap.offset.y, data->game2d.size_block.x
				* minimap.scale, data->game2d.size_block.x * minimap.scale};
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
}

// void	draw_player(t_data *data, t_player *player, t_minimap *minimap) // UNFINISHED
// {
// 	t_rect	current_rect;

// 	current_rect = (t_rect){player->pos.x * minimap->scale
// 		+ minimap->offset.x, player->pos.y * minimap->scale
// 		+ minimap->offset.y, player->size.x * minimap->scale,
// 		player->size.y * minimap->scale};
// 	draw_rect(&data->img, current_rect, 0x526D82);
// 	raycasting(data, player, minimap);
// }

// void	raycasting(t_data *data, t_player *player, t_minimap *minimap)
// {
// 	t_ray	*ray;

// 	ray->rayIndex = 0;
// 	ray->angleStep = FOV_ANGLE / minimap->size.x;
// 	ray->rayAngle = player->angle - (FOV_ANGLE / 2);
// 	ray->mapX = (int)player->pos.x;
// 	ray->mapY = (int)player->pos.y;
// 	while (ray->rayIndex < minimap->size.x)
// 	{
// 		ray->rayDirX = cos(ray->rayAngle * M_PI / 180);
// 		ray->rayDirY = sin(ray->rayAngle * M_PI / 180);
// 		ray->deltaDistX = abs(1 / ray->rayDirX);
// 		ray->deltaDistY = abs(1 / ray->rayDirY);
// 		if (ray->rayDirX < 0)
// 		{
// 			ray->stepX = -1;
// 			ray->sideDistX = (player->pos.x - (int)player->pos.x) * ray->deltaDistX;
// 		}
// 		else
// 		{
// 			ray->stepX = 1;
// 			ray->sideDistX = ((int)player->pos.x + 1 - player->pos.x) * ray->deltaDistX;
// 		}
// 		if (ray->rayDirY < 0)
// 		{
// 			ray->stepY = -1;
// 			ray->sideDistY = (player->pos.y - (int)player->pos.y) * ray->deltaDistY;
// 		}
// 		else
// 		{
// 			ray->stepY = 1;
// 			ray->sideDistY = ((int)player->pos.y + 1 - player->pos.y) * ray->deltaDistY;
// 		}
// 	ray->hit = 0;
// 	ray->mapX = (int)player->pos.x;
// 	ray->mapY = (int)player->pos.y;
// 	while (!ray->hit)
// 	{
// 		if (ray->sideDistX < ray->sideDistY)
// 		{
// 			ray->sideDistX += ray->deltaDistX;
// 			ray->mapX += ray->stepX;
// 		}
// 		else
// 		{
// 			ray->sideDistY += ray->deltaDistY;
// 			ray->mapY += ray->stepY;
// 		}
// 		if (data->map[ray->mapY][ray->mapX] == '1')
// 			ray->hit = 1;
// 	}
// 	t_vector2	start_pos = (t_vector2){(player->pos.x + player->size.x / 2) * minimap->scale
// 		+ minimap->offset.x, (player->pos.y  + player->size.x / 2) * minimap->scale
// 			+ minimap->offset.y};
// 	t_vector2	end_pos = (t_vector2){ray->mapX * minimap->scale
// 		+ minimap->offset.x, ray->mapY * minimap->scale
// 			+ minimap->offset.y};
// 	ray->rayAngle += ray->angleStep;
// 	ray->rayIndex++;
// 	draw_line(&data->img, start_pos, end_pos, 0x00ffff, 5 * minimap->scale);
// 	}
// }
