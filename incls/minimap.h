#ifndef MINIMAP_H
# define MINIMAP_H

#include "data.h"
#include "draw.h"

typedef struct s_minimap
{
	t_vector2	pos;
	t_vector2	size;
} t_minimap;

typedef	struct s_player
{
	t_fvector2	pos;
	t_vector2	size;
	float		speed;
} t_player;

typedef struct s_game
{
	t_minimap	minimap;
	t_player	player;
} t_game;

void	draw_minimap(t_data *data);

#endif
