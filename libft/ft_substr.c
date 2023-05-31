/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:56:55 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:36:53 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Allocates and returns a substring of the given string.
@param [s] The string to extract the substring from.
@param [start] The starting index of the substring in
the string s.
@param [len] The length of the substring to extract.
@return A pointer to the newly allocated substring, or
NULL if the allocation fails.
This function allocates memory for the substring, and copies
len characters from the string s starting
at index start. If start is greater than or equal to the length
of the string s, or if len is 0,
the function returns an empty string. If len is greater than
the remaining characters after start,
the function copies only the remaining characters.
The returned substring is null-terminated.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (start >= ft_strlen(s))
		len = 0;
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == (NULL))
		return (NULL);
	while (len > 0)
	{
		ptr[i] = s[start + i];
		i++;
		len --;
	}
	ptr[i] = '\0';
	return (ptr);
}
