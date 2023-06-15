#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "data.h"
#include "vector2.h"


char		**parse_map(char *filename, t_vector2 map_size);
t_vector2	get_map_size(char *filename);

bool	parser(char *filename, t_data *data)
{

	if (!parse_textures_and_colors())
		return (false);
	data->map_size = get_map_size(filename);
	if (data->map_size.x == 0 || data->map_size.y == 0) // TODO say map size is invalid
		return (false);

	data->map = parse_map(filename, data->map_size);
	if (data->map == NULL)
		return (false);

	// prints the map
	int i = 0;
	printf("map:\n");
	while (data->map[i])
	{
			printf("%s\n", data->map[i]);

		i++;
	}

	return (true);
}

