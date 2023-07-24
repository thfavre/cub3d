#ifndef  GAME2D_H
# define GAME2D_H

# include "data.h"
# include "draw.h"
# include "rect.h"
# include <math.h>

# define MINIMAP_OFFSET 30
# define NB_RAYS SCREEN_WIDTH
# define FOV_DEG 60
# define FOV_RAD FOV_DEG * M_PI / 180
# define PLAYER_ROTATE_SPEED 5
# define ANGLE_INCREMENT FOV_RAD / (NB_RAYS - 1) // new

typedef struct s_ray // NEW
{
	float		ray_angle;
	float		vertical_ray;
	float		horizontal_ray;
	float		ray_length;
	float		ray_length_correct;
	int			wall_height;
	double		wall_x;
	double		step;
	int			tex_x;
	t_img		texture;
	t_fvector2	side;
	t_fvector2	delta;
	t_fvector2	player_center;
	t_fvector2	ray_pos;
} t_ray;

typedef struct s_wall
{
	t_rect	rect;
} t_wall;

typedef struct s_player
{
	t_fvector2	fpos;
	t_vector2	pos; // TODO put in rect with size?
	t_vector2	size;
	float		speed;
	float		angle;
} t_player;

typedef struct s_minimap
{
	t_vector2	offset;
	t_vector2	size;
	float		scale;
} t_minimap;

typedef struct s_game2d
{
	int			walls_count;
	t_vector2	size_block; // should it be just an int?
	t_minimap	minimap;
	t_player	player;
	t_wall		*walls;
} t_game2d;

typedef struct s_data t_data;

void	init_settings(t_data *data);
void	draw_minimap(t_data *data, char **map, t_minimap minimap);
void	update_player(t_data *data, t_player *player);
void	check_collisions_x(t_game2d *game2d, t_player *player);
void	check_collisions_y(t_game2d *game2d, t_player *player);
float	raycasting_up(t_data *data, t_ray *ray, float scale);
float	raycasting_down(t_data *data, t_ray *ray, float scale);
float	raycasting_right(t_data *data, t_ray *ray, float scale);
float	raycasting_left(t_data *data, t_ray *ray, float scale);

#endif
