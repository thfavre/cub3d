/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:28:32 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/10 14:17:01 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
Writes a single character to the given file descriptor.
@param [c] The character to write.
@param [fd] The file descriptor to write to.
@return None.
Writes the character c to the file descriptor fd.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
