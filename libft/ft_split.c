/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:32:17 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:38:45 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

static char	*wordcreate(int start, int end, char const *s)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 2) * sizeof(char));
	if (!word)
		return (NULL);
	while (start <= end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

/**
Splits a string into an array of strings using a delimiter character.
@param s The string to split.
@param c The delimiter character.
@return A pointer to an array of strings resulting from the split operation.
If the allocation fails or if the string is empty, returns NULL.
Note: The returned array of strings should be freed using ft_free_tab.
Note: If two consecutive delimiter characters are found,
an empty string is added to the array.
*/
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		var[3];

	tab = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	var[0] = 0;
	var[2] = -1;
	while (s[var[0]])
	{
		var[1] = 0;
		while (s[var[1] + var[0]] && s[var[0] + var[1]] != c)
		{
			if (s[var[0] + var[1] + 1] == '\0' || s[(var[0] + var[1]) + 1] == c)
				tab[++var[2]] = wordcreate(var[0], var[0] + var[1], s);
			var[1]++;
		}
		var[0] += var[1];
		if (s[var[0]] != '\0')
			var[0]++;
	}
	tab[++var[2]] = (NULL);
	return (tab);
}
