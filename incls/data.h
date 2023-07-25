#ifndef DATA_H
# define DATA_H

# include <stdbool.h>

# include "image.h"
# include "vector2.h"
# include "keycodes.h"
# include "sprite.h"
# include "game2d.h"
# include "libft.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

typedef struct s_textures // TODO put in textures.h ?
{
	t_img	NO;
	t_img	SO;
	t_img	WE;
	t_img	EA;
	int		F;
	int		C;
}	t_textures;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	bool		key_pressed[MAX_KEYS];
	bool		key_just_pressed[MAX_KEYS];
	bool		mouse_just_pressed;
	bool		mouse_pressed;
	t_vector2	mouse_pos;
	float		dt;
	char		**map;
	t_vector2	map_size;
	t_textures	textures;
	t_game2d	game2d;
	t_ray		*ray; // TODO rename to rays
	float		fov_deg; // put all this in a struct?
	int			nb_rays;
	int 		walls_height;
	float 		walls_y_offset;
	float		map_mult;
	bool		textured;
	int			untextured_color;
}	t_data;

#endif
