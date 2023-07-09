#ifndef  GAME2D_H
# define GAME2D_H

#include "data.h"
#include "draw.h"
#include "rect.h"
#include <math.h>

# define MINIMAP_OFFSET 30
# define FOV_ANGLE 60

// typedef struct s_ray UNFINISHED
// {
// 	float		angleStep;
// 	float		rayAngle;
// 	float		rayDirX;
// 	float		rayDirY;
// 	float		deltaDistX;
// 	float		deltaDistY;
// 	float		sideDistX;
// 	float		sideDistY;
// 	int			rayIndex;
// 	int			stepX;
// 	int			stepY;
// 	int			mapX;
// 	int			mapY;
// 	int			hit;
// } t_ray;

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

#endif
