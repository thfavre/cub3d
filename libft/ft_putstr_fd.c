/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:33:50 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:18:53 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Outputs a string to a file descriptor.
@param s The string to output.
@param fd The file descriptor to write to.
@return void.
This function writes the string 's' to the file descriptor 'fd'.
Example usage:
char *str = "Hello, world!";
int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
ft_putstr_fd(str, fd);
close(fd);
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
}
