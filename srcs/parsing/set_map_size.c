#include "vector2.h"
#include "stdbool.h"
#include <fcntl.h>
#include <stdio.h>


bool	set_map_size(char *filename, t_vector2 *map_size)
{
	int		fd;
	char	*line;
	int		line_index;
	int		line_length;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error, '%s' is not a valid file\n", filename);
		return (false);
	}
	line = get_next_line(fd);
	line_index = 0;
	line_length = 0;
	while (line[line_index] != '\0')
	{
		if (line[line_index] == ' ')
			line_length++;
		line_index++;
	}
	map_size->x = line_length;
	map_size->y = 1;
	while (get_next_line(fd))
		map_size->y++;
	close(fd);
	return (true);
}

