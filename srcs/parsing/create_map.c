#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "libft.h"
#include "vector2.h"

char **handle_map_error(char **map, char *line, int error_line, int error_column);
void *free_map(char **map);

char **create_map(int fd, t_vector2 map_size)
{
	char	*line;
	int		line_index;
	t_vector2	map_index;
	char	**map;

	map = ft_calloc(map_size.y + 1, sizeof(char *));
	map_index.y = -1;
	while (map && ++map_index.y < map_size.y)
	{
		line = get_next_line(fd);
		map_index.x = -1;
		line_index = 0;
		map[map_index.y] = ft_calloc(map_size.x + 1, sizeof(char));
		if (map[map_index.y] == NULL)
			return (free_map(map));
		while (++map_index.x < map_size.x)
		{
			map[map_index.y][map_index.x] = line[line_index++];
			if (line[line_index] != ' ' && line[line_index] != '\n' && line[line_index] != '\0')
				return (handle_map_error(map, line, map_index.x, map_index.y));
			line_index++; // to skip the space
		}
	}
	return (map);
}

char **handle_map_error(char **map, char *line, int error_column, int error_line)
{
	printf("Error, the character '%c' at line %d col %d should be a space\n",
		line[error_column*2+1], error_line + 1, error_column * 2 + 2);
	map[error_line + 1] = NULL; // to stop the loop in free_map
	free_map(map);
	return NULL;
}

void *free_map(char **map)
{
	int	i;

	if (map == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}
