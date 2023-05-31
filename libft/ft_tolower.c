/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:12:27 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:36:38 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
The ft_tolower() function converts an uppercase
letter to its corresponding lowercase letter.
@param c The character to be converted.
@return The corresponding lowercase letter if the
input is an uppercase letter; otherwise, it returns
the input character as is.
There are no side effects for this function.
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
