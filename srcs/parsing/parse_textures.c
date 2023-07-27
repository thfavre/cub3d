/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:23:20 by thomas            #+#    #+#             */
/*   Updated: 2023/07/27 01:22:10 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx.h"
#include "libft.h"
#include "textures.h"
#include "parsing.h"

void	free_split(char **split);
bool	parse_texture(void *mlx, char *line, t_img *sprite, char *name);
bool	set_texture(void *mlx, t_img *sprite, char *path, char *name);

bool	parse_textures(void *mlx, int fd, t_textures *textures)
{
	if (!parse_texture(mlx, get_next_unempty_line(fd), &textures->north, "NO")
		|| !parse_texture(mlx, get_next_unempty_line(fd),
			&textures->south, "SO")
		|| !parse_texture(mlx, get_next_unempty_line(fd), &textures->west, "WE")
		|| !parse_texture(mlx, get_next_unempty_line(fd), &textures->east, "EA")
		|| !parse_color(get_next_unempty_line(fd), &textures->floor, "F")
		|| !parse_color(get_next_unempty_line(fd), &textures->celling, "C"))
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
	if (textures->north.img != NULL)
		mlx_destroy_image(mlx, textures->north.img);
	if (textures->south.img != NULL)
		mlx_destroy_image(mlx, textures->south.img);
	if (textures->west.img != NULL)
		mlx_destroy_image(mlx, textures->west.img);
	if (textures->east.img != NULL)
		mlx_destroy_image(mlx, textures->east.img);
}
