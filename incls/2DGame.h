#ifndef _2DGAME_H
# define _2DGAME_H

#include "vector2.h"
#include "rect.h"

# define CELL_SIZE 80

//--- player.c ---//

typedef	struct s_player
{
	t_fvector2	pos;
	int			size;
	float		moving_speed;
} t_player;

typedef struct s_obstacles
{
	int		number;
	t_rect	*rects;
} t_obstacles;

typedef struct s_game // or call it s_2dgame ??
{
	t_player	player;
	t_obstacles	obstacles;
} t_game;

void	init_player(t_player *player, char **map);
void	update_player(t_img *img, bool *keypressed, t_player *player, t_obstacles obstacles, float dt);


#endif
