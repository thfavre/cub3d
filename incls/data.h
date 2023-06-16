#ifndef DATA_H
# define DATA_H

# include <stdbool.h>

# include "image.h"
# include "vector2.h"
# include "keycodes.h"

typedef struct s_sprite
{
	t_vector2	size;
	void		*img;
}				t_sprite;

typedef struct s_textures
{
	t_sprite	NO;
	t_sprite	SO;
	t_sprite	WE;
	t_sprite	EA;
	t_sprite	F;
	int		C;
}				t_textures;

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
	t_textures	textures;

} t_data;

#endif
