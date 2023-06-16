#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "mlx.h"
#include "libft.h"
#include "data.h"
#include "vector2.h"


char		**parse_map(int fd, char *filename, t_vector2 *map_size);
t_vector2	get_map_size(char *filename);


char	*get_next_unempty_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL && ft_strcmp(line, "\n") == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

bool	parse_texture(void *mlx, char *line, t_sprite *sprite, char *expected_name)
{
	char	**splited_line;

	if (line == NULL)
		return (false);
	splited_line = ft_split(line, ' ');
	if (splited_line == NULL)
		return (false);
	if (ft_strcmp(splited_line[0], expected_name) != 0)
	{
		printf("Error, expected '%s' but got '%s'\n", expected_name, splited_line[0]);
		return (false);
	}
	if (splited_line[1] == NULL)
	{
		printf("Error, expected a path after '%s'\n", expected_name);
		return (false);
	}
	if (splited_line[1][ft_strlen(splited_line[1]) - 1] == '\n')
		splited_line[1][ft_strlen(splited_line[1]) - 1] = '\0';
	sprite->img = mlx_xpm_file_to_image(mlx, splited_line[1], &sprite->size.x, &sprite->size.y);
	if (sprite->img == NULL)
	{
		printf("Error, invalid path '%s'\n", splited_line[1]);
		return (false);
	}
	return (true);
}

bool	parser(char *filename, t_data *data)
{
	int	fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error, '%s' is not a valid file\n", filename);
		return (false);
	}

	if (!parse_texture(data->mlx, get_next_unempty_line(fd), &data->textures.NO, "NO")
		|| !parse_texture(data->mlx, get_next_unempty_line(fd), &data->textures.SO, "SO")
		|| !parse_texture(data->mlx, get_next_unempty_line(fd), &data->textures.WE, "WE")
		|| !parse_texture(data->mlx, get_next_unempty_line(fd), &data->textures.EA, "EA"))
	{
		printf("Error, invalid texture\n");
		return (false);
	}

	data->map = parse_map(fd, filename, &data->map_size);
	if (data->map == NULL)
		return (false);

	close(fd);
	// if (!parse_textures_and_colors())
	// 	return (false);
	// data->map_size = get_map_size(filename);
	// if (data->map_size.x == 0 || data->map_size.y == 0) // TODO say map size is invalid
	// 	return (false);

	// data->map = parse_map(filename, data->map_size);
	// if (data->map == NULL)
	// 	return (false);

	// // prints the map
	int i = 0;
	printf("map:\n");
	while (data->map[i])
	{
			printf("%s\n", data->map[i]);

		i++;
	}
	printf("map_size: %d %d\n", data->map_size.x, data->map_size.y);
	return (true);
}

