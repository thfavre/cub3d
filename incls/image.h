#ifndef IMAGE_H
# define IMAGE_H

# include "vector2.h"

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_vector2	size;
}			t_img;

#endif
