/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:31:57 by fabien            #+#    #+#             */
/*   Updated: 2023/03/10 14:09:58 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_power(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/**
Converts an integer to a string.
@param n The integer to be converted.
@return A string representation of the integer.
The function allocates memory for the string representation of the integer.
The memory should be freed using free() when it is no longer needed.
Example usage:
int num = 123;
char *str = ft_itoa(num);
printf("The string representation of %d is %s\n", num, str);
free(str);
*/
char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = check_power(n) + 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != '\0')
	{
		res[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (res);
}
