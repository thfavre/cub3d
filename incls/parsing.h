/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:21:04 by tastybao          #+#    #+#             */
/*   Updated: 2023/07/26 21:21:05 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include "sprite.h"
# include "vector2.h"
# include "data.h"

bool	parse_color(char *line, int *color, char *expected_name);
bool	parse_texture(void *mlx, char *line, t_img *sprite, char *name);
void	free_textures(void *mlx, t_textures *textures);
char	**parse_map(int fd, char *filename, t_vector2 *map_size);
bool	check_map_validity(char **map);
char	*get_next_unempty_line(int fd);

#endif
