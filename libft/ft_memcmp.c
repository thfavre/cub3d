/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:50:29 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:39:22 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Compares the first n bytes of two memory blocks pointed to by s1 and s2.
@param s1 Pointer to the first memory block to be compared.
@param s2 Pointer to the second memory block to be compared.
@param n Number of bytes to compare.
@return An integer less than, equal to, or greater than zero,
depending on whether the
first n bytes of s1 is less than, equal to, or greater than
the first n bytes of s2.
This function compares the first n bytes of the two memory blocks
pointed to by s1 and s2.
The comparison is done byte by byte, and if a mismatch is found,
it returns the difference between the mismatched bytes as an integer.
If no mismatches are found, it returns 0.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}
