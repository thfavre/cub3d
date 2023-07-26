/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:23:17 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:23:17 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		open_cub_file(char *filename);
bool	parse_textures(void *mlx, int fd, t_textures *textures);

bool	parser(char *filename, t_data *data)
{
	int		fd;
	char	*line;

	fd = open_cub_file(filename);
	if (fd == -1)
		return (false);
	if (!parse_textures(data->mlx, fd, &data->textures))
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
	if (!check_map_validity(data->map))
	{
		free_textures(data->mlx, &data->textures);
		free_map(data->map);
		return (false);
	}
	return (true);
}

int	open_cub_file(char *filename)
{
	int	fd;

	if (ft_strlen(filename) <= 4 || ft_strcmp(filename + \
										ft_strlen(filename) - 4, ".cub") != 0)
	{
		printf("Error, '%s' should have a '.cub extension\n", filename);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		printf("Error, '%s' is not a valid file\n", filename);
	return (fd);
}
