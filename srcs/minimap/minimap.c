/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:14:52 by tastybao          #+#    #+#             */
/*   Updated: 2023/07/27 01:52:24 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "color.h"
#include "game2d.h"

void	draw_player(t_data *data, t_player *player, t_minimap *minimap);
void	draw_rays(t_data *data, t_ray *ray, t_minimap *minimap);

void	draw_minimap(t_data *data, char **map, t_minimap minimap)
{
	int		x;
	int		y;
	t_rect	current_rect;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			current_rect = (t_rect){x * (data->game2d.size_block.x
					* minimap.scale * data->map_mult) + minimap.offset.x - 1, y
				* (data->game2d.size_block.y * minimap.scale * data->map_mult)
				+ minimap.offset.y - 1, data->game2d.size_block.x
				* minimap.scale * data->map_mult - 2, data->game2d.size_block.x
				* minimap.scale * data->map_mult - 2};
			if (map[y][x] == '1')
				draw_rect(&data->img, current_rect, 0x34495e);
			else if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'E' || map[y][x] == 'W')
				draw_rect(&data->img, current_rect, 0xecf0f1);
		}
	}
	draw_player(data, &data->game2d.player, &data->game2d.minimap);
	draw_rays(data, data->rays, &minimap);
}

void	draw_player(t_data *data, t_player *player, t_minimap *minimap)
{
	t_rect	current_rect;

	current_rect = (t_rect){player->pos.x * minimap->scale * data->map_mult
		+ minimap->offset.x, player->pos.y * minimap->scale * data->map_mult
		+ minimap->offset.y, player->size.x * minimap->scale * data->map_mult,
		player->size.y * minimap->scale * data->map_mult};
	draw_rect(&data->img, current_rect, 0xf39c12);
}

void	draw_rays(t_data *data, t_ray *ray, t_minimap *minimap)
{
	int	i;

	i = -1;
	while (++i < data->nb_rays)
	{
		draw_line(&data->img, (t_vector2){ray[i].player_center.x
			* minimap->scale * data->map_mult + MINIMAP_OFFSET,
			ray[i].player_center.y * minimap->scale
			* data->map_mult + MINIMAP_OFFSET},
			(t_vector2){(ray[i].player_center.x + cos(ray[i].ray_angle)
				* ray[i].ray_length) * minimap->scale * data->map_mult
			+ MINIMAP_OFFSET, (ray[i].player_center.y
				- sin(ray[i].ray_angle) * ray[i].ray_length)
			* minimap->scale * data->map_mult + MINIMAP_OFFSET},
			0xf1c40f);
	}
}
