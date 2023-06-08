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
} t_data;

#endif
