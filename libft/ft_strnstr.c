/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:29:16 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:29:04 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Locate the first occurrence of a substring in a string, where not more than len
characters are searched. A null-terminated character sequence is called a
string. The function locates the first occurrence of the null-terminated string
needle in the string haystack, where not more than len characters are searched.
Characters that appear after a `\0' character are not searched.
@param [haystack] The string to search in.
@param [needle] The substring to search for.
@param [len] The maximum number of characters to search.
@return Returns a pointer to the beginning of the located substring, or NULL if
the substring is not found.
This function has no side effects.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	if (needle[0] == '\0')
		return (&((char *)haystack)[i]);
	while (haystack[i] && i <= len)
	{
		j = 0;
		while ((needle[j] == haystack[j + i]) && (needle[j] != '\0') \
	&& (((i + j) < len)))
			j++;
		if (j == ft_strlen(needle))
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
