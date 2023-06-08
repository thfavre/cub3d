#include "data.h"

int	on_close(t_data *data)
{
	free(data->mlx);
	exit(0);
	return (0);
}
