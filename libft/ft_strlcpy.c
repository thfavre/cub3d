/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:59:47 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:37:59 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Copies a string from source to destination up to a maximum of
dstsize - 1 characters, null-terminating the result.
If dstsize is 0 or src is NULL, the function returns the length
of the source string.
@param [dst] Pointer to the destination array.
@param [src] Pointer to the source string.
@param [dstsize] Maximum number of characters to copy.
@return The length of the source string.
If the destination string is smaller than the source string,
the destination string will not be null-terminated.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0 || src == (NULL))
		return ((size_t)ft_strlen(src));
	while (i < dstsize - 1 && (i < ft_strlen(src)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ((size_t)ft_strlen(src));
}
