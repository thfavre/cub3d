#ifndef PARSING_H
# define PARSING_H

#include <stdbool.h>

#include "sprite.h"
#include "vector2.h"
#include "data.h" // only for t_textures


bool	parse_color(char* line, int* color, char* expected_name);
bool	parse_texture(void *mlx, char *line, t_sprite *sprite, char *expected_name);
void	free_textures(void *mlx, t_textures *textures);
char	**parse_map(int fd, char *filename, t_vector2 *map_size);
bool	check_map_validity(char **map);
char	*get_next_unempty_line(int fd);


#endif
