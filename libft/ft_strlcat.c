/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:40:05 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:38:08 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Appends the NUL-terminated string src to the end of dst
(dst must have enough space to hold both dst and src).
The size of dst must be passed as a parameter to prevent buffer overflows.
@param [dst] Pointer to the destination string.
@param [src] Pointer to the string to be appended.
@param [dstsize] The size of the destination buffer.
@return Returns the length of the concatenated string
(initial length of dst + length of src).
This function has no side effects.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;

	i = 0;
	lendst = 0;
	while (dst[lendst] && lendst < dstsize)
		lendst++;
	while (src[i] && (i + lendst + 1) < dstsize)
	{
		dst[i + lendst] = src[i];
		i++;
	}
	if (lendst != dstsize)
		dst[i + lendst] = '\0';
	return (ft_strlen(src) + lendst);
}
