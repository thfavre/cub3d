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

int	set_color_red_value(int color, int redValue)
{
	if (redValue > 255)
		redValue = 255;
	else if (redValue < 0)
		redValue = 0;
	int clearColorRed = color & 0xFF00FFFF;
	int newRed = redValue << 16;
	int newColor = clearColorRed | newRed;
	return (newColor);
}

int	set_color_green_value(int color, int greenValue)
{
	if (greenValue > 255)
		greenValue = 255;
	else if (greenValue < 0)
		greenValue = 0;
	int clearColorGreen = color & 0xFFFF00FF;
	int newGreen = greenValue << 8;
	int newColor = clearColorGreen | newGreen;
	return (newColor);
}

int	set_color_blue_value(int color, int blueValue)
{
	if (blueValue > 255)
		blueValue = 255;
	else if (blueValue < 0)
		blueValue = 0;
	int clearColorBlue = color & 0xFFFFFF00;
	int newBlue = blueValue;
	int newColor = clearColorBlue | newBlue;
	return (newColor);
}

// int	add_color(int color, int to_add_color)
// {
// 	int	red;
// 	int	green;
// 	int	blue;

// 	red = (color >> 16) + (to_add_color >> 16);
// 	green = ((color >> 8) & 0xFF) + ((to_add_color >> 8) & 0xFF);
// 	blue = (color & 0xFF) + (to_add_color & 0xFF);
// 	if (red > 255)
// 		red = 255;
// 	if (green > 255)
// 		green = 255;
// 	if (blue > 255)
// 		blue = 255;
// 	return (rgb(red, green, blue));
// }

// int	sub_color(int color, int to_sub_color)
// {
// 	int	red;
// 	int	green;
// 	int	blue;

// 	red = (color >> 16) - (to_sub_color >> 16);
// 	green = ((color >> 8) & 0xFF) - ((to_sub_color >> 8) & 0xFF);
// 	blue = (color & 0xFF) - (to_sub_color & 0xFF);
// 	if (red < 0)
// 		red = 0;
// 	if (green < 0)
// 		green = 0;
// 	if (blue < 0)
// 		blue = 0;
// 	return (rgb(red, green, blue));
// }
