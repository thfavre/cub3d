/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:05:41 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:31:34 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Converts the given character to uppercase.
@param [c] The character to convert.
@return The uppercase equivalent of the character, or the original
character if it is already uppercase or not a lowercase letter.
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
