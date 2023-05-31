/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:22:03 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:41:15 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Allocates a block of memory for an array of elements,
each of them size bytes long, and initializes
all its bits to zero. The function returns a
pointer to the allocated memory block.
@param count Number of elements to be allocated.
@param size Size of each element in bytes.
@return Pointer to the newly allocated memory block,
or NULL if the allocation fails.
The function has the side effect of allocating a block of memory
and setting all its bits to zero using ft_bzero().
Example usage:
int *nums = (int *)ft_calloc(10, sizeof(int));
// Allocates an array of 10 integers, all set to zero.
*/
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc(count * size);
	if (ptr == (NULL))
		return ((NULL));
	ft_bzero(ptr, count * size);
	return (ptr);
}
