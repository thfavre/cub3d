#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "vector2.h"
#include "libft.h"

// char **create_map(int fd, t_vector2 map_size);
// void *handle_map_error(char **map, char *line, int error_line, int error_column);
// void *free_map(char **map);


int	get_file_line_number(char *filename)
{
	int		fd;
	char	*line;
	int		line_number;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error, '%s' is not a valid file\n", filename);
		return (-1);
	}
	line_number = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		line_number++;
	}
	close(fd);
	return (line_number);
}


char	*get_next_unempty_line(int fd); // declare in parser.c



char		**parse_map(int fd, char *filename, t_vector2 *map_size)
{
	char	*line;
	char	**map;
	int		file_line_number;

	line = get_next_unempty_line(fd);
	if (line == NULL)
		return (NULL);
	file_line_number = get_file_line_number(filename);
	if (file_line_number == -1)
		return (NULL);
	map = ft_calloc(file_line_number + 1, sizeof(char *));
	if (map == NULL)
		return (NULL);
	*map_size = (t_vector2){0, 0};
	while (line != NULL)
	{
		if (line[ft_strlen(line)-1] == '\n')
			line[ft_strlen(line)-1] = '\0';
		map[map_size->y] = line;
		if (ft_strlen(line) > map_size->x)
			map_size->x = ft_strlen(line);
		line = get_next_line(fd); // TODO: free line when error
		map_size->y++;
	}
	return (map);
}

// char **create_map(int fd, t_vector2 map_size)
// {
// 	char	*line;
// 	int		y;

// 	char	**map;

// 	map = ft_calloc(map_size.y + 1, sizeof(char *));
// 	if (map == NULL)
// 		return (NULL);
// 	y = -1;
// 	while (++y < map_size.y)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			return (free_map(map));
// 		if (line[ft_strlen(line)-1] == '\n')
// 			line[ft_strlen(line)-1] = '\0';
// 		map[y] = line;
// 		free(line);
// 	}
// 	return (map);
// }

// void *free_map(char **map)
// {
// 	int	i;

// 	if (map == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (map[i] != NULL)
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// 	return (NULL);
// }
