/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:10:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:37:48 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Compare two strings up to a given number of characters.
@param [s1] Pointer to the first string.
@param [s2] Pointer to the second string.
@param [n] Maximum number of characters to compare.
@return An integer less than, equal to, or greater than
zero if the first n bytes
of s1 is found, respectively, to be less than, to match,
or be greater than the first
n bytes of s2.
This function compares the first n bytes of s1 and s2.
It returns an integer less than,
equal to, or greater than zero if s1 is found, respectively,
to be less than, to match,
or be greater than s2. The comparison is done using unsigned
characters, so that '\200' is greater than '\0'.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
