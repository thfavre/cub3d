/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:14:55 by tastybao          #+#    #+#             */
/*   Updated: 2023/07/26 21:14:56 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "game2d.h"
#include "color.h"

char	get_tile_type_from_pos(char **map, t_vector2 size_block, t_vector2 pos);

float	raycasting_up(t_data *data, t_ray *ray, float scale)
{
	int	i;

	i = 0;
	ray->ray_pos = ray->player_center;
	ray->side.y = fmod(ray->ray_pos.y, data->game2d.size_block.y);
	ray->side.x = -(tan(ray->ray_angle - M_PI / 2) * ray->side.y);
	ray->ray_pos.x += ray->side.x;
	ray->ray_pos.y -= ray->side.y;
	ray->delta.y = data->game2d.size_block.y;
	ray->delta.x = -tan(ray->ray_angle - M_PI / 2) * ray->delta.y;
	while (true)
	{
		if (get_tile_type_from_pos(data->map, data->game2d.size_block,
				(t_vector2){ray->ray_pos.x + i * ray->delta.x, ray->ray_pos.y
				- i * ray->delta.y - 1}) == '1')
			break ;
		i++;
	}
	ray->ray_pos.x += i * ray->delta.x;
	ray->ray_pos.y -= i * ray->delta.y;
	return (sqrt(pow(ray->ray_pos.x - ray->player_center.x, 2)
			+ pow(ray->ray_pos.y - ray->player_center.y, 2)));
}

float	raycasting_down(t_data *data, t_ray *ray, float scale)
{
	int	i;

	i = 0;
	ray->ray_pos = ray->player_center;
	ray->side.y = data->game2d.size_block.y - fmod(ray->ray_pos.y,
			data->game2d.size_block.y);
	ray->side.x = (tan(ray->ray_angle - M_PI / 2) * ray->side.y);
	ray->ray_pos.x += ray->side.x;
	ray->ray_pos.y += ray->side.y;
	ray->delta.y = data->game2d.size_block.y;
	ray->delta.x = tan(ray->ray_angle - M_PI / 2) * ray->delta.y;
	while (true)
	{
		if (get_tile_type_from_pos(data->map, data->game2d.size_block,
				(t_vector2){ray->ray_pos.x + i * ray->delta.x, ray->ray_pos.y
				+ i * ray->delta.y}) == '1')
			break ;
		i++;
	}
	ray->ray_pos.x += i * ray->delta.x;
	ray->ray_pos.y += i * ray->delta.y;
	return (sqrt(pow(ray->ray_pos.x - ray->player_center.x, 2)
			+ pow(ray->ray_pos.y - ray->player_center.y, 2)));
}

float	raycasting_right(t_data *data, t_ray *ray, float scale)
{
	int	i;

	i = 0;
	ray->ray_pos = ray->player_center;
	ray->side.x = data->game2d.size_block.x - fmod(ray->ray_pos.x,
			data->game2d.size_block.x);
	ray->side.y = -(tan(ray->ray_angle) * ray->side.x);
	ray->ray_pos.x += ray->side.x;
	ray->ray_pos.y += ray->side.y;
	ray->delta.x = data->game2d.size_block.x;
	ray->delta.y = -tan(ray->ray_angle) * ray->delta.x;
	while (true)
	{
		if (get_tile_type_from_pos(data->map, data->game2d.size_block,
				(t_vector2){ray->ray_pos.x + i * ray->delta.x,
				ray->ray_pos.y + i * ray->delta.y}) == '1')
			break ;
		i++;
	}
	ray->ray_pos.x += i * ray->delta.x;
	ray->ray_pos.y += i * ray->delta.y;
	return (sqrt(pow(ray->ray_pos.y - ray->player_center.y, 2)
			+ pow(ray->ray_pos.x - ray->player_center.x, 2)));
}

float	raycasting_left(t_data *data, t_ray *ray, float scale)
{
	int	i;

	i = 0;
	ray->ray_pos = ray->player_center;
	ray->side.x = fmod(ray->ray_pos.x, data->game2d.size_block.x);
	ray->side.y = -(tan(ray->ray_angle) * ray->side.x);
	ray->ray_pos.x -= ray->side.x;
	ray->ray_pos.y -= ray->side.y;
	ray->delta.x = data->game2d.size_block.x;
	ray->delta.y = -tan(ray->ray_angle) * ray->delta.x;
	while (true)
	{
		if (get_tile_type_from_pos(data->map, data->game2d.size_block,
				(t_vector2){ray->ray_pos.x - i * ray->delta.x - 1,
				ray->ray_pos.y - i * ray->delta.y}) == '1')
			break ;
		i++;
	}
	ray->ray_pos.x -= i * ray->delta.x;
	ray->ray_pos.y -= i * ray->delta.y;
	return (sqrt(pow(ray->ray_pos.y - ray->player_center.y, 2)
			+ pow(ray->ray_pos.x - ray->player_center.x, 2)));
}

char	get_tile_type_from_pos(char **map, t_vector2 size_block, t_vector2 pos)
{
	int	x;
	int	y;
	int	line;

	line = -1;
	while (map[++line])
		;
	line--;
	x = (int)pos.x / size_block.x;
	y = (int)pos.y / size_block.y;
	if (x < 0 || y < 0 || y > line || x > ft_strlen(map[y]))
		return ('1');
	return (map[y][x]);
}
