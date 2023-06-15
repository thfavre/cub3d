#include <fcntl.h>
#include <stdio.h>

#include "vector2.h"
#include "stdbool.h"
#include "libft.h"

t_vector2	get_map_size(char *filename)
{
	int			fd;
	char		*line;
	t_vector2	map_size;

	fd = open(filename, O_RDONLY);
	map_size = (t_vector2){0, 0};
	if (fd == -1)
	{
		printf("Error, '%s' is not a valid file\n", filename);
		return (map_size);
	}
	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;

		if (ft_strlen(line)-1 > map_size.x)
			map_size.x = ft_strlen(line)-1;

		free(line);
		map_size.y++;
	}
	close(fd);
	printf("map_size: %d %d\n", map_size.x, map_size.y);
	return (map_size);
}

