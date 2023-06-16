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

int	open_file(char *filename);

bool	parser(char *filename, t_data *data)
{
	int		fd;
	char	*line;

	if (ft_strlen(filename) <= 4 || ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
	{
		printf("Error, '%s' should have a '.cub extension\n", filename);
		return (false);
	}
	fd = open_file(filename);
	if (fd == -1)
		return (false);
	if (!parse_texture(data->mlx, get_next_unempty_line(fd), &data->textures.NO, "NO")
		|| !parse_texture(data->mlx, get_next_unempty_line(fd), &data->textures.SO, "SO")
		|| !parse_texture(data->mlx, get_next_unempty_line(fd), &data->textures.WE, "WE")
		|| !parse_texture(data->mlx, get_next_unempty_line(fd), &data->textures.EA, "EA")
		|| !parse_color(get_next_unempty_line(fd), &data->textures.F, "F")
		|| !parse_color(get_next_unempty_line(fd), &data->textures.C, "C"))
		return (false);
	data->map = parse_map(fd, filename, &data->map_size);
	if (data->map == NULL)
		return (false);
	close(fd);
	return (true);

	// DEBUG
	// int i = 0;
	// printf("map:\n");
	// while (data->map[i])
	// {
	// 		printf("%s\n", data->map[i]);
	// 	i++;
	// }
	// printf("map_size: %d %d\n", data->map_size.x, data->map_size.y);
}

int	open_file(char *filename)
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
