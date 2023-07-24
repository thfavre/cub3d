#include "data.h"
#include "game2d.h"
#include "color.h"

int	get_color(t_img *img, int x, int y);

void	raycasting(t_data *data, t_player *player, t_minimap *minimap) // TODO check for the forbidden angles (+- delta_allowed_angle) (parfois on s'approche tres pres des valeurs interdites de tan (pas exactement a cause des floats))
{
	t_ray	ray;
	float	vertical_ray;
	float	horizontal_ray;
	int		i;

	ray.player_center = (t_fvector2){player->pos.x + player->size.x / 2,
		player->pos.y + player->size.x / 2};
	ray.angle_increment = FOV_RAD / (NB_RAYS - 1);
	i = -1;
	while (++i < NB_RAYS)
	{
		ray.ray_angle = player->angle - FOV_RAD / 2 + (i * ray.angle_increment);
		ray.ray_angle = fmod(ray.ray_angle, 2 * M_PI);
		if (ray.ray_angle < M_PI && ray.ray_angle >= 0 && ray.ray_angle != M_PI)
			vertical_ray = raycasting_up(data, ray, minimap->scale);
		else
			vertical_ray = raycasting_down(data, ray, minimap->scale);
		if (ray.ray_angle < M_PI / 2 || ray.ray_angle >= 3 * M_PI / 2)
			horizontal_ray = raycasting_right(data, ray, minimap->scale);
		else
			horizontal_ray = raycasting_left(data, ray, minimap->scale);
		// draw ray on minimap
		float	ray_length = (vertical_ray < horizontal_ray) ? vertical_ray : horizontal_ray; // ciao norminette
		draw_line(&data->img, (t_vector2){ray.player_center.x * minimap->scale
			+ MINIMAP_OFFSET, ray.player_center.y * minimap->scale + MINIMAP_OFFSET},
			(t_vector2){(ray.player_center.x + cos(ray.ray_angle) * ray_length)
			* minimap->scale + MINIMAP_OFFSET, (ray.player_center.y - sin(ray.ray_angle)
			* ray_length) * minimap->scale + MINIMAP_OFFSET}, C_DARKOLIVEGREEN3);
		// 3d! (good luck)
		float ray_length_correct = ray_length * cos(fabs(player->angle - ray.ray_angle));
		int wall_height = (int)(SCREEN_HEIGHT / (ray_length_correct / 50));
		// draw_textureless_walls(data, wall_height, color);
		// textures
		t_img	texture;
		if (vertical_ray < horizontal_ray && ray.ray_angle < M_PI && ray.ray_angle >= 0 && ray.ray_angle != M_PI)
			texture = data->textures.SO;
		else if (vertical_ray < horizontal_ray)
			texture = data->textures.NO;
		else if (vertical_ray > horizontal_ray && (ray.ray_angle < M_PI / 2 || ray.ray_angle >= 3 * M_PI / 2))
			texture = data->textures.EA;
		else if (vertical_ray > horizontal_ray)
			texture = data->textures.WE;

		double wall_x; // where exactly the wall was hit
		if (vertical_ray < horizontal_ray)
			wall_x = (ray.player_center.x + ray_length * cos(ray.ray_angle)) / 50;// / 40;
		else
			wall_x = (ray.player_center.y - ray_length * sin(ray.ray_angle)) / 50;// / 40;

		wall_x -= floor(wall_x);
		// printf("wall_x: %f\n", wall_x);
		int TEX_WIDTH = texture.size.x;
		// x coordinate on the texture
		int tex_x = (int)((wall_x) * (double)TEX_WIDTH);
		if (vertical_ray < horizontal_ray && ray.ray_angle > M_PI) // flip the texture
			tex_x = TEX_WIDTH - tex_x - 1;
		if (vertical_ray > horizontal_ray && (ray.ray_angle >= M_PI / 2 && ray.ray_angle < 3 * M_PI / 2)) // flip the texture
			tex_x = TEX_WIDTH - tex_x - 1;

		int TEX_HEIGHT = texture.size.y;

		// How much to increase the texture coordinate y per screen pixel
		double step = 1.0 * TEX_HEIGHT / wall_height; // y
		int draw_start = -wall_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = wall_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		// Starting texture coordinate
		double tex_pos = (draw_start - SCREEN_HEIGHT / 2 + wall_height / 2) * step; //y
		for (int y = draw_start; y < draw_end; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int tex_y = (int)tex_pos & (TEX_HEIGHT - 1);
			tex_pos += step;
			int color = get_color(&texture, tex_x, tex_y);
			draw_pixel(&data->img, (t_vector2){SCREEN_WIDTH - i, y}, color);
		}
	}
}

int	get_color(t_img *img, int x, int y)
{
	char	*dst;
	if (!img)
	{
		printf("img is NULL\n");
		return (0);
	}
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
