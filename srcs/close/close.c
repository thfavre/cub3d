#include "data.h"

void	*free_map(char **map);
void	free_textures(void *mlx, t_textures *textures);

int	on_close(t_data *data)
{
	free(data->game2d.walls);
	free_map(data->map);
	free_textures(data->mlx, &data->textures);
	free(data->mlx);
	exit(0);
	return (0);
}
