#ifndef DATA_H
# define DATA_H

# include <stdbool.h>

# include "image.h"
# include "vector2.h"
# include "keycodes.h"
# include "sprite.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
typedef struct s_textures // TODO put in textures.h ?
{
	t_sprite	NO;
	t_sprite	SO;
	t_sprite	WE;
	t_sprite	EA;
	int			F;
	int			C;
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
	// t_vector2	*walls_positions;
	t_textures	textures;


} t_data;

#endif
