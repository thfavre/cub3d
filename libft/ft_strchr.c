/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:05:42 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:22:21 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Searches for the first occurrence of a character in a string.
@param [s] The string to search in.
@param [c] The character to search for.
@return A pointer to the first occurrence of the character in the string,
or NULL if the character is not found.
This function searches for the first occurrence of the character c (converted
to a char) in the string s. The terminating null character is considered to
be part of the string, so the function will return a pointer to it if c is
'\0'.
*/
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (i < ((int)ft_strlen(s) + 1))
	{
		if (((char *) s)[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
