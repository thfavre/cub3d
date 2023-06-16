#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>

#include "libft.h"
#include "vector2.h"


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

// bool parse_texture(char *line, t_textures textures)
// {

// 	// current_texture =
// 	return (true);
// }

bool parse_textures_and_colors(char *filename)
{
	// int			fd;
	// char		*line;
	// t_textures	textures;

	// textures = (t_textures){0};
	// fd = open(filename, O_RDONLY);
	// if (fd == -1)
	// {
	// 	printf("Error, '%s' is not a valid file\n", filename);
	// 	return (false);
	// }
	// while (true)
	// {
	// 	line = get_next_line(fd);
	// 	if (line == NULL)
	// 		return false;
	// 	if (ft_strcmp(line, "\n") != 0)
	// 	{
	// 		if (!parse_texture(line, &textures))
	// 			{
	// 				printf("Error, invalid texture\n")
	// 				return (false);
	// 			}
	// 	}
	// 	free(line);
	// }
	return (true);
}
