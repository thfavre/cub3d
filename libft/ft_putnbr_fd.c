/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:50:10 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:18:07 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Writes an integer to a file descriptor.
@param n The integer to write.
@param fd The file descriptor to write to.
@return None.
The function writes the integer to the given file descriptor using the
ft_putchar_fd function. If the integer is -2147483648, the string
"-2147483648" is written instead.
Example usage:
int fd = open("file.txt", O_WRONLY);
ft_putnbr_fd(42, fd); // Writes "42" to the file
ft_putnbr_fd(-123, fd); // Writes "-123" to the file
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', fd);
		}
		if (n <= 9)
			ft_putchar_fd(n + '0', fd);
		if (n > 9)
		{
			ft_putnbr_fd(((n / 10)), fd);
			ft_putnbr_fd(((n % 10)), fd);
		}
	}
}
