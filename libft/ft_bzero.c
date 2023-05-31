/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:47:42 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:40:18 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Sets the first n bytes of the block of memory pointed
by s to zero (interpreted as '\0').
@param s Pointer to the block of memory to be zeroed.
@param n Size of the block of memory to be zeroed, in bytes.
@return This function does not return a value.
The function has the side effect of modifying the memory pointed by s,
setting its first n bytes to zero.
Example usage:
char buffer[10];
ft_bzero(buffer, sizeof(buffer)); // Sets the buffer to all zeroes
*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}
