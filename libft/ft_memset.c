/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:27:48 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:41:08 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Fills the first 'len' bytes of the memory area pointed to by
'b' with the constant byte 'c'.
@param b Pointer to the memory area to be filled.
@param c The value to be set. The value is passed as an int,
but converted to unsigned char.
@param len The number of bytes to be filled.
@return The original value of 'b'.
This function has the side effect of modifying the memory area pointed to by 'b'.
Example usage:
char arr[6] = "Hello";
ft_memset(arr+1, 'a', 2); // Result: "Hallo"
*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)(b + i) = c;
		i++;
	}
	return (b);
}
