/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:46:37 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:39:34 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Checks whether a given character is a printable character, i.e.,
whether its value is between 32 and 126 (inclusive).
@param c The character to be checked.
@return 1 if the character is a printable character, 0 otherwise.
The function has no side effects.
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
