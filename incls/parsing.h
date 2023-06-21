#ifndef PARSING_H
# define PARSING_H

#include <stdbool.h>

#include "sprite.h"
#include "vector2.h"

bool	parse_color(char* line, int* color, char* expected_name);
bool	parse_texture(void *mlx, char *line, t_sprite *sprite, char *expected_name);
char	**parse_map(int fd, char *filename, t_vector2 *map_size);
char	*get_next_unempty_line(int fd);

#endif
