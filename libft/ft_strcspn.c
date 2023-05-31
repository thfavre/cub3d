/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berard <berard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:13:14 by fgrasset          #+#    #+#             */
/*   Updated: 2023/04/06 10:23:32 by berard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Returns the length of the initial segment of the string 's' that
contains no characters from the string 'reject'.
@param s Pointer to the string to search for characters not in 'reject'.
@param reject Pointer to the string containing characters to reject.
@return The length of the initial segment of 's' containing no characters
from 'reject'.
This function iterates over the characters in the string 's' until it finds
a character that is also present in the string 'reject'.
At that point, it returns the index of that character in the string 's', which
represents the length of the initial segment of 's'
containing no characters from 'reject'.
If no characters in 's' are found to be in 'reject',
the function returns the length of 's'.
Example usage:
char *s = "hello";
char *reject = "oe";
int len = ft_strcspn(s, reject); // len == 2
*/
int	mystrcspnft_strcspn(char *s, char *reject)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
