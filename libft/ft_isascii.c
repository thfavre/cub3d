/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:21:17 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:39:40 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Checks whether a given character is a valid ASCII character, i.e.,
whether its value is between 0 and 127 (inclusive).
@param c The character to be checked.
@return 1 if the character is a valid ASCII character, 0 otherwise.
The function has no side effects.
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
