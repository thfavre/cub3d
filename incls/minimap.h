#ifndef MINIMAP_H
# define MINIMAP_H

#include "data.h"
#include "draw.h"

typedef struct s_minimap
{
	t_fvector2	pos;
	t_fvector2	size;
} t_minimap;

typedef	struct s_player
{
	t_fvector2	pos;
	t_fvector2	size;
	int			speed;
} t_player;

void	draw_minimap(t_data *data)

#endif
