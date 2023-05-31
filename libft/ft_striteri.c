/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:00:47 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:38:30 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Applies a function to each character in a string, passing both
the index and the character as arguments to the function.
@param s The string to apply the function to.
@param f The function to apply to each character in the string.
@return void
This function applies the function f to each character in the string s,
passing both the index and the character as arguments to f.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = -1;
	while (s[++i])
		(*f)(i, &s[i]);
}
