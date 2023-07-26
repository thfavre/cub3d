/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:23:21 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:23:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "color.h"
#include "parsing.h"

bool	validate_line(char *line, char *expected_name);
bool	parse_rgb(char *rgb_string, int *colors);
void	free_split(char **split);

bool	parse_color(char *line, int *color, char *expected_name)
{
	char	**splited_line;
	int		colors[3];

	if (!validate_line(line, expected_name))
	{
		free(line);
		return (false);
	}
	splited_line = ft_split(line, ' ');
	free(line);
	if (!parse_rgb(splited_line[1], colors))
	{
		free_split(splited_line);
		return (false);
	}
	*color = rgb(colors[0], colors[1], colors[2]);
	free_split(splited_line);
	return (true);
}

bool	validate_line(char *line, char *expected_name)
{
	char	**splited_line;

	if (line == NULL)
		return (false);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	splited_line = ft_split(line, ' ');
	if (splited_line == NULL)
		return (false);
	if (ft_strcmp(splited_line[0], expected_name) != 0)
	{
		printf("Error, expected '%s' \but got '%s'\n", expected_name,
			splited_line[0]);
		free_split(splited_line);
		return (false);
	}
	if (splited_line[1] == NULL || splited_line[2] != NULL)
	{
		free_split(splited_line);
		printf("Error, expected a color in this format: '%s R,G,B'\n",
			expected_name);
		return (false);
	}
	free_split(splited_line);
	return (true);
}

bool	parse_rgb(char *rgb_string, int *colors)
{
	char	**str_rgb;
	int		i;

	str_rgb = ft_split(rgb_string, ',');
	if (!str_rgb || !str_rgb[0] || !str_rgb[1] || !str_rgb[2] || str_rgb[3])
	{
		free_split(str_rgb);
		return (printf("Error, expected color in 'R,G,B' format\n") == 0);
	}
	i = -1;
	while (++i < 3)
	{
		if (!ft_is_str_digit(str_rgb[i]))
		{
			printf("Error, invalid color '%s', must be numeric\n", str_rgb[i]);
			break ;
		}
		colors[i] = ft_atoi(str_rgb[i]);
		if (colors[i] < 0 || colors[i] > 255)
			printf("Error, invalid color '%s', must be between\
0 and 255\n", str_rgb[i]);
		if (colors[i] < 0 || colors[i] > 255)
			break ;
	}
	free_split(str_rgb);
	return (i == 3);
}
