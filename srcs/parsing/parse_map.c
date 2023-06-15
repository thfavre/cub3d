#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "libft.h"
#include "vector2.h"

char **create_map(int fd, t_vector2 map_size);
void *handle_map_error(char **map, char *line, int error_line, int error_column);
void *free_map(char **map);

char **parse_map(char *filename, t_vector2 map_size)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error, '%s' is not a valid file\n", filename);
		return (NULL);
	}

	map = create_map(fd, map_size);
	close(fd);
	return (map);
}

char **create_map(int fd, t_vector2 map_size)
{
	char	*line;
	int		y;

	char	**map;

	map = ft_calloc(map_size.y + 1, sizeof(char *));
	if (map == NULL)
		return (NULL);
	y = -1;
	while (++y < map_size.y)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (free_map(map));
		if (line[ft_strlen(line)-1] == '\n')
			line[ft_strlen(line)-1] = '\0';
		map[y] = line;
		free(line);
	}
	return (map);
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
