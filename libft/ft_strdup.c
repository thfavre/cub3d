/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:23:20 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:40:55 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Returns a newly allocated string which is a duplicate of the given string.
@param s1 The string to duplicate.
@return A pointer to the newly allocated duplicated string,
or NULL if allocation failed.
This function allocates a new memory block and copies the contents of
the given string into it. The new string will be null-terminated, and can
be modified or freed without affecting the original string.
*/
char	*ft_strdup(const char *s1)
{
	size_t	len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	i = 0;
	ptr = malloc(len * sizeof(char));
	if (ptr == (NULL))
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
