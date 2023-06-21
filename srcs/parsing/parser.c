#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "mlx.h"
#include "libft.h"
#include "data.h"
#include "vector2.h"
#include "color.h"
#include "parsing.h"

int	open_cub_file(char *filename);
bool	parse_textures(void *mlx, int fd, t_textures *textures);


// TODO :
// check if only one player is present
// check if map is valid (only 0, 1, 2, NSEW, spaces)
// check if all (0 + player) are surrounded by 1
// free all mallocs if error
bool	parser(char *filename, t_data *data)
{
	int		fd;
	char	*line;

	fd = open_cub_file(filename);
	if (fd == -1)
		return (false);
	if (!parse_textures(data->mlx, fd, &data->textures)) // also parse colors
	{
		close(fd);
		return (false);
	}
	data->map = parse_map(fd, filename, &data->map_size);
	close(fd);
	if (data->map == NULL)
	{
		free_textures(data->mlx, &data->textures);
		return (false);
	}
	if (!check_map_validity(data->map)) // put in parse_map?
	{
		free_textures(data->mlx, &data->textures);
		free_map(data->map);
		return (false);
	}
	// DEBUG
	// int i = 0;
	// printf("map:\n");
	// while (data->map[i])
	// {
	// 		printf("%s\n", data->map[i]);
	// 	i++;
	// }
	// printf("map_size: %d %d\n", data->map_size.x, data->map_size.y);
	return (true);
}

int	open_cub_file(char *filename)
{
	int	fd;

	if (ft_strlen(filename) <= 4 || ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
	{
		printf("Error, '%s' should have a '.cub extension\n", filename);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		printf("Error, '%s' is not a valid file\n", filename);
	return (fd);
}
