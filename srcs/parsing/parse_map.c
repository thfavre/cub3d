#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "vector2.h"
#include "libft.h"
#include "data.h" // only for t_textures
#include "parsing.h"

void	*free_map(char **map);

int		get_file_line_number(char *filename);

char		**parse_map(int fd, char *filename, t_vector2 *map_size)
{
	char	*line;
	char	**map;
	int		file_line_number;

	file_line_number = get_file_line_number(filename);
	if (file_line_number == -1) // is it necessary to have an error here ?
		return (NULL);
	line = get_next_unempty_line(fd);
	if (line == NULL)
		return (NULL);
	map = ft_calloc(file_line_number + 1, sizeof(char *));
	*map_size = (t_vector2){0, 0};
	while (map && line != NULL)
	{
		if (line[ft_strlen(line)-1] == '\n')
			line[ft_strlen(line)-1] = '\0';
		map[map_size->y] = line;
		if (ft_strlen(line) > map_size->x)
			map_size->x = ft_strlen(line);
		line = get_next_line(fd); // TODO: free line when error, but how to know if it is an error or end of file ?
		// if (line == NULL)
		// 	return (free_map(map));
		map_size->y++;
	}
	return (map);
}

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

bool	check_map_validity(char **map)
{
	t_vector2			pos;
	char				cell;
	static int			player_count = 0; // for norminette....

	pos.y = -1;
	while (map[++pos.y] != NULL)
	{
		pos.x = -1;
		while (map[pos.y][++pos.x] != '\0')
		{
			cell = map[pos.y][pos.x];
			if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
			{
				if (++player_count == 1)
					continue ;
				printf("Error, there must be exactly one player in the map\n");
				return (false);
			}
			if (cell == '0' || cell == '1' || cell == ' ')
				continue ;
			printf("Error, invalid character '%c' \
at (%d, %d)\n", cell, pos.x + 1, pos.y + 1);
			return (false);
		}
	}
	return (true);
}
