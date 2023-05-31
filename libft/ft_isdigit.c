/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:49:40 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:39:37 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Checks whether a given character is a digit, i.e.,
whether its value is between '0' and '9'.
@param c The character to be checked.
@return 1 if the character is a digit, 0 otherwise.
The function has no side effects.
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
