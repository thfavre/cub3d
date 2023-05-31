/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:27:22 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:39:43 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Checks whether a given character is an alphabetic character, i.e.,
whether it is either an uppercase or lowercase letter.
@param c The character to be checked.
@return 1 if the character is an alphabetic character, 0 otherwise.
The function has no side effects.
*/
int	ft_isalpha(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
		return (1);
	else
		return (0);
}
