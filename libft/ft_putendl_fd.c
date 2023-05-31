/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:48:05 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:17:32 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Outputs the string s followed by a newline character to the file descriptor fd.
@param s The string to output.
@param fd The file descriptor to write to.
@return None.
This function writes the characters of the string s to the file descriptor fd
using the ft_putchar_fd function. It then writes a newline character to the same
file descriptor using ft_putchar_fd.
*/
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	ft_putchar_fd('\n', fd);
}
