#include <stdio.h>

#include "data.h"
#include "keycodes.h"
#include "draw.h"
#include "game2d.h"
#include "mlx.h"

void on_update_utils(t_data *data); // Put the function in update.c?
int	get_avrage_fps(float dt);


// t_fvector2	player_pos; // px, py
// t_fvector2	player_dir; // pdx, pdy
// float		player_angle; // pa
// int			tile_size; // ps
# include <math.h>
# include "libft.h"
char	get_tile_type_from_pos(char **map, t_vector2 size_block, t_vector2 pos)
{
	int x = (int)pos.x / size_block.x;
	int y = (int)pos.y / size_block.y;
	if (x < 0 || y < 0 || y >= 14 || x >= ft_strlen(map[y]))//TODO not hardcode 14, find mapsize
		return ('1');
	// printf("x : %d, y : %d ,f y %f\n", x, y, (float)pos.y / (float)size_block.y);
	return (map[y][x]);
}
#include "draw.h"
void	simulate3d(t_data *data, t_game2d *game2d, t_player *player)
{
	t_vector2	ray_pos;
	float scale = game2d->minimap.scale;
	t_vector2 player_center = (t_vector2){player->pos.x + player->size.x / 2, player->pos.y + player->size.y / 2};

	int num_rays = 200;
	int fov = 30; // in degrees
	float fov_rad = fov * M_PI / 180; // in radians
	float angle_increment =  fov_rad / num_rays; // Divide the total angle range (60 degrees) by the number of rays


	for (int i = 0; i < num_rays; i++)
	{
		float ray_angle = player->angle - fov_rad/2 + (i * angle_increment); // Adjust the ray angle based on the current iteration
		// Horizontal lines
		if (ray_angle < M_PI && ray_angle >= 0 && ray_angle != M_PI)
		{
			ray_pos = player_center;

			// player pos
			int y = ray_pos.y % game2d->size_block.y; // height to the closest next wall up
			int x = 1 - (int)(tan(ray_angle - M_PI/2) * y); // width to next wall up
			ray_pos.x += x;
			ray_pos.y -= y;
			float y2 = game2d->size_block.y; // height to next wall up
			float x2 = 1 - tan(ray_angle- M_PI/2) * y2; // width to next wall up

			int d = 0;
			while (true)
			{
				if (get_tile_type_from_pos(data->map, game2d->size_block, (t_vector2){ray_pos.x + d*x2, ray_pos.y - d*y2 - 1}) == '1')
					break;
				d++;
			}
			ray_pos.x += d * x2;
			ray_pos.y -= d * y2;
			// printf("raypos : %d, %d\n", ray_pos.x, ray_pos.y);
			// printf("type : %c\n", get_tile_type_from_pos(data->map, game2d->size_block, (t_vector2){ray_pos.x, ray_pos.y-1})); // -1 correct?
			draw_line(&data->img, (t_vector2){player_center.x * scale +MINIMAP_OFFSET, player_center.y * scale + MINIMAP_OFFSET}, (t_vector2){(ray_pos.x) * scale + MINIMAP_OFFSET, (ray_pos.y) * scale + MINIMAP_OFFSET}, C_RED, 1);

		}
	}


}

int on_update(t_data *data)
{
	static bool in_menu;
	draw_background(&data->img, data->textures.F);

	// To make drop the frame rate
	if (data->key_pressed[K_T])
	{
		for (int y = 500; y < SCREEN_HEIGHT; y++)
			for (int x = 0; x < SCREEN_WIDTH; x++)
			{
				for (int i = 0; i < 3; i++)
					draw_rect(&data->img, (t_rect){x, y, 4, 4}, C_WHEAT1);
			}
	}

	draw_background(&data->img, data->textures.F);

	// hide mouse when on window
	// if (data->mouse_pos.x >= 0 && data->mouse_pos.x < SCREEN_WIDTH && \
	// 	data->mouse_pos.y >= 0 && data->mouse_pos.y < SCREEN_HEIGHT)
	// 	mlx_mouse_hide(data->mlx, data->win);
	// else
	// 	mlx_mouse_show(data->mlx, data->win);

	// mouse center screen
	// if (!in_menu)
	// 	mlx_mouse_move(data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	if (data->key_just_pressed[K_SPACE])
		data->game2d.minimap.scale += 0.1;



	// if (data->key_just_pressed[K_SPACE])
	// {
	// 	in_menu = !in_menu;
	// 	if (in_menu)
	// 		printf("In menu\n");
	// }
	update_player(data, &data->game2d.player);
	draw_minimap(data, data->map, data->game2d.minimap);

	get_avrage_fps(data->dt);
	simulate3d(data, &data->game2d, &data->game2d.player);
	on_update_utils(data);
}

