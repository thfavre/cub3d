/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:14:58 by tastybao          #+#    #+#             */
/*   Updated: 2023/07/27 01:52:19 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "game2d.h"
#include "color.h"

int		get_color(t_img *img, int x, int y);
void	register_rays(t_data *data, t_ray *ray, t_game2d *game2d, int i);
void	register_textures(t_data *data, t_ray *ray);
void	draw_textures(t_data *data, t_ray *ray, int i);

void	raycasting(t_data *data, t_player *player, t_minimap *minimap)
{
	int		i;

	data->rays = malloc(sizeof(t_ray) * data->nb_rays);
	if (!data->rays)
		return ;
	i = -1;
	while (++i < data->nb_rays)
	{
		register_rays(data, &data->rays[i], &data->game2d, i);
		register_textures(data, &data->rays[i]);
		draw_textures(data, &data->rays[i], i);
	}
}

void	register_rays(t_data *data, t_ray *ray, t_game2d *game2d, int i)
{
	ray->player_center = (t_fvector2){game2d->player.pos.x
		+ game2d->player.size.x / 2, game2d->player.pos.y
		+ game2d->player.size.x / 2};
	ray->ray_angle = game2d->player.angle - data->fov_deg * M_PI
		/ 180 / 2 + (i * data->fov_deg * M_PI / 180
			/ (data->nb_rays - 1));
	ray->ray_angle = fmod(ray->ray_angle, 2 * M_PI);
	if (ray->ray_angle < M_PI && ray->ray_angle >= 0 && ray->ray_angle != M_PI)
		ray->vertical_ray = raycasting_up(data, ray, game2d->minimap.scale);
	else
		ray->vertical_ray = raycasting_down(data, ray, game2d->minimap.scale);
	if (ray->ray_angle < M_PI / 2 || ray->ray_angle >= 3 * M_PI / 2)
		ray->horizontal_ray = raycasting_right(data, ray,
				game2d->minimap.scale);
	else
		ray->horizontal_ray = raycasting_left(data, ray, game2d->minimap.scale);
	if (ray->vertical_ray < ray->horizontal_ray)
		ray->ray_length = ray->vertical_ray;
	else
		ray->ray_length = ray->horizontal_ray;
	ray->ray_length_correct = ray->ray_length * cos(fabs(game2d->player.angle
				- ray->ray_angle));
	ray->wall_height = (int)(SCREEN_HEIGHT / (ray->ray_length_correct
				/ data->walls_height));
}

void	register_textures(t_data *data, t_ray *ray)
{
	if (ray->vertical_ray < ray->horizontal_ray && ray->ray_angle < M_PI
		&& ray->ray_angle >= 0 && ray->ray_angle != M_PI)
		ray->texture = data->textures.south;
	else if (ray->vertical_ray < ray->horizontal_ray)
		ray->texture = data->textures.north;
	else if (ray->vertical_ray > ray->horizontal_ray && (ray->ray_angle < M_PI
			/ 2 || ray->ray_angle >= 3 * M_PI / 2))
		ray->texture = data->textures.east;
	else if (ray->vertical_ray > ray->horizontal_ray)
		ray->texture = data->textures.west;
	if (ray->vertical_ray < ray->horizontal_ray)
		ray->wall_x = (ray->player_center.x + ray->ray_length
				* cos(ray->ray_angle)) / 50;
	else
		ray->wall_x = (ray->player_center.y - ray->ray_length
				* sin(ray->ray_angle)) / 50;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)((ray->wall_x) * (double)ray->texture.size.x);
	if (ray->vertical_ray < ray->horizontal_ray && ray->ray_angle > M_PI)
		ray->tex_x = ray->texture.size.x - ray->tex_x - 1;
	if (ray->vertical_ray > ray->horizontal_ray && ray->ray_angle >= M_PI / 2
		&& ray->ray_angle < 3 * M_PI / 2)
		ray->tex_x = ray->texture.size.x - ray->tex_x - 1;
	ray->step = 1.0 * ray->texture.size.y / ray->wall_height;
}

void	draw_textures(t_data *data, t_ray *ray, int i)
{
	int		draw_start;
	int		draw_end;
	int		color;
	double	tex_pos;
	int		tex_y;

	draw_start = (-ray->wall_height + SCREEN_HEIGHT) / 2 + data->walls_y_offset;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (ray->wall_height + SCREEN_HEIGHT) / 2 + data->walls_y_offset;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	tex_pos = (draw_start - SCREEN_HEIGHT / 2 + ray->wall_height / 2
			- data->walls_y_offset) * ray->step;
	while (draw_start++ < draw_end)
	{
		tex_y = (int)tex_pos & (ray->texture.size.y - 1);
		tex_pos += ray->step;
		color = data->untextured_color;
		if (data->textured)
			color = get_color(&ray->texture, ray->tex_x, tex_y);
		draw_pixel(&data->img, (t_vector2){SCREEN_WIDTH - i
			* ((float)SCREEN_WIDTH / (float)data->nb_rays),
			draw_start}, color);
	}
}

int	get_color(t_img *img, int x, int y)
{
	char	*dst;

	if (!img)
		return (0);
	dst = img->addr;
	if (!dst)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	if (x >= img->size.x || y >= img->size.y)
		return (0);
	dst += y * img->line_len + x * (img->bpp / 8);
	return (*(int *)dst);
}
