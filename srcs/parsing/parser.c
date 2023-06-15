#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "data.h"
#include "vector2.h"


char **create_map(int fd, t_vector2 map_size);

bool	parser(char *filename, t_data *data)
{
	if (!set_map_size(filename, &data->map_size))
		return (false);


	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error, '%s' is not a valid file\n", filename);
		return (false);
	}
	data->map = create_map(fd, data->map_size);
	close(fd);
	if (data->map == NULL)
		return (false);

	// prints the map
	int i = 0;
	while (data->map[i])
	{
			printf("%s\n", data->map[i]);

		i++;
	}

	return (true);
}

