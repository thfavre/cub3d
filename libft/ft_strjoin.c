/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:56:45 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:40:43 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Concatenates two strings s1 and s2 into a new string allocated in memory.
@param s1 The first string to concatenate.
@param s2 The second string to concatenate.
@return The new string resulting from the concatenation of s1 and s2, or NULL
if the allocation fails. This function allocates memory
for a new string that contains
the characters of s1 followed by the characters of s2.
If either s1 or s2 is NULL, an empty string will be used instead.
If the allocation fails, NULL will be returned.
Example usage:
char *s1 = "Hello";
char *s2 = " world!";
char *result = ft_strjoin(s1, s2);
printf("%s", result); // Output: "Hello world!"
free(result); // Remember to free the memory allocated by ft_strjoin
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ptr;

	i = -1;
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	i--;
	while (s2[++i - ft_strlen(s1)])
		ptr[i] = s2[i - ft_strlen(s1)];
	ptr[i] = '\0';
	return (ptr);
}
