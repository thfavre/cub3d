#include "image.h"
#include "rect.h"

void	draw_background(t_img *img, int color) // Not needed, delete?
{
	draw_rect(img, (t_rect){0, 0, img->size.x, img->size.y}, color);
}
