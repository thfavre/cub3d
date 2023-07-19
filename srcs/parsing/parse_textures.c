#include <stdbool.h>
#include <stdlib.h>

#include "mlx.h"
#include "libft.h"
// #include "sprite.h"
#include "data.h"
#include "parsing.h"

void	free_split(char **split);
bool	parse_texture(void *mlx, char *line, t_img *sprite, char *name);
bool	set_texture(void *mlx, t_img *sprite, char *path, char *name);

bool	parse_textures(void *mlx, int fd, t_textures *textures)
{
	if (!parse_texture(mlx, get_next_unempty_line(fd), &textures->NO, "NO")
		|| !parse_texture(mlx, get_next_unempty_line(fd), &textures->SO, "SO")
		|| !parse_texture(mlx, get_next_unempty_line(fd), &textures->WE, "WE")
		|| !parse_texture(mlx, get_next_unempty_line(fd), &textures->EA, "EA")
		|| !parse_color(get_next_unempty_line(fd), &textures->F, "F")
		|| !parse_color(get_next_unempty_line(fd), &textures->C, "C"))
	{
		free_textures(mlx, textures);
		return (false);
	}
	return (true);
}

bool	parse_texture(void *mlx, char *line, t_img *sprite, char *name)
{
	char	**splited_line;

	if (line == NULL)
		return (false);
	splited_line = ft_split(line, ' ');
	free(line);
	if (splited_line == NULL)
		return (false);
	if (ft_strcmp(splited_line[0], name) != 0)
	{
		printf("Error, expected '%s' but got '%s'\n", name, splited_line[0]);
		free_split(splited_line);
		return (false);
	}
	if (!set_texture(mlx, sprite, splited_line[1], name))
	{
		free_split(splited_line);
		return (false);
	}
	free_split(splited_line);
	return (true);
}

bool	set_texture(void *mlx, t_img *sprite, char *path, char *name)
{
	if (path == NULL)
	{
		printf("Error, expected a path after '%s'\n", name);
		return (false);
	}
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = '\0';
	// img = malloc(sizeof(t_img));
	sprite->img = mlx_xpm_file_to_image(mlx, path, &sprite->size.x,
			&sprite->size.y);
	if (sprite->img == NULL)
	{
		printf("Error, invalid path '%s'\n", path);
		return (false);
	}
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->line_len, &sprite->endian);
	return (true);
}

void	free_textures(void *mlx, t_textures *textures)
{
	if (textures->NO.img != NULL)
		mlx_destroy_image(mlx, textures->NO.img);
	if (textures->SO.img != NULL)
		mlx_destroy_image(mlx, textures->SO.img);
	if (textures->WE.img != NULL)
		mlx_destroy_image(mlx, textures->WE.img);
	if (textures->EA.img != NULL)
		mlx_destroy_image(mlx, textures->EA.img);
}
