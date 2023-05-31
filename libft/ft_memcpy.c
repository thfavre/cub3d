/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:54:26 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:13:00 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Copies n bytes from the memory area src to the memory area dst.
The memory areas must not overlap.
@param dst The pointer to the destination buffer to copy to.
@param src The pointer to the source buffer to copy from.
@param n The number of bytes to copy.
@return A pointer to the destination buffer (dst).
There are no side effects for this function.
Example usage:
char src[] = "Hello, world!";
char dst[20];
ft_memcpy(dst, src, sizeof(src));
printf("%s", dst);
Output: "Hello, world!"
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == (NULL) && src == (NULL))
		return (0);
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
