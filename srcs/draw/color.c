/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:56:25 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:22:35 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
 * Converts a red, green, blue values to a single 32-bit integer
 *
 * @param red: red value
 * @param green: green value
 * @param blue: blue value
 *
 * @return 32-bit integer containing red, green, blue values
*/
int	rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	set_color_red_value(int color, int red_value)
{
	int	clear_color_red;
	int	new_red;

	if (red_value > 255)
		red_value = 255;
	else if (red_value < 0)
		red_value = 0;
	clear_color_red = color & 0xFF00FFFF;
	new_red = red_value << 16;
	return (clear_color_red | new_red);
}

int	set_color_green_value(int color, int green_value)
{
	int	clear_color_green;
	int	new_green;

	if (green_value > 255)
		green_value = 255;
	else if (green_value < 0)
		green_value = 0;
	clear_color_green = color & 0xFFFF00FF;
	new_green = green_value << 8;
	return (clear_color_green | new_green);
}

int	set_color_blue_value(int color, int blue_value)
{
	int	clear_color_blue;
	int	new_blue;

	if (blue_value > 255)
		blue_value = 255;
	else if (blue_value < 0)
		blue_value = 0;
	clear_color_blue = color & 0xFFFFFF00;
	new_blue = blue_value;
	return (clear_color_blue | new_blue);
}
