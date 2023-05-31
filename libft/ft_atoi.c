/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:57:05 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:40:24 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/**
Converts a string of digits to its integer representation.
The function ignores leading whitespace characters,
followed by an optional sign character ('+' or '-'),
and converts subsequent digits to an integer value. The
function returns the converted integer value.
@param str The string to be converted to an integer.
@return The integer value corresponding to the input string.
The function has no side effects.
Example usage:
const char *str = " -1234 ";
int result = ft_atoi(str); // Returns -1234
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sgn;
	int	atoi;

	i = 0;
	sgn = 1;
	atoi = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sgn = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		atoi = (atoi * 10) + (str[i] - '0');
		i++;
	}
	return (atoi * sgn);
}
