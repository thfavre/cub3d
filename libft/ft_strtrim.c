/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:12:51 by fabien            #+#    #+#             */
/*   Updated: 2023/03/10 14:37:10 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checking_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/**
Returns a new string by trimming characters from the
beginning and end of the input string that are found in the set string.
@param [s1] The input string to be trimmed.
@param [set] The set of characters to be trimmed from
the beginning and end of the input string.
@return The new string with trimmed characters.
This function allocates memory for the new string using
malloc, so the caller is responsible for freeing the memory.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		i;
	int		j;
	char	*ptr;

	i = ft_strlen(s1) - 1;
	end = 0;
	j = -1;
	while (i >= 0 && checking_set(s1[i], set))
	{
		end++;
		i--;
	}
	i = 0;
	while (s1[i] && checking_set(s1[i], set) && end != (int)ft_strlen(s1))
		i++;
	ptr = malloc((ft_strlen(s1) - (i + end) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[++j + i] && ((i + j) < ((int)ft_strlen(s1) - end)))
		ptr[j] = s1[j + i];
	ptr[j] = '\0';
	return (ptr);
}
