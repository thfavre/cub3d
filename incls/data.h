#ifndef DATA_H
# define DATA_H

# include <stdbool.h>

# include "image.h"
# include "vector2.h"
# include "keycodes.h"

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	bool		key_pressed[MAX_KEYS];
	t_vector2	mouse_pos;
	float		dt;

	char		**map;
	t_vector2	map_size;
	t_vector2	*walls_positions;
	int			NORTH_COLOR;// put all the colors in a struct?
	int			SOUTH_COLOR;
	int			WEST_COLOR;
	int			EAST_COLOR;
	int			CEILING_COLOR;
	int			FLOOR_COLOR;
} t_data;

#endif
