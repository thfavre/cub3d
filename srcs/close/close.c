#include "data.h"

void *free_map(char **map);

int	on_close(t_data *data)
{
	free(data->mlx);
	// free_map(data->map);
	exit(0);
	return (0);
}
