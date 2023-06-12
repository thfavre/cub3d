#ifndef DRAW_H
# define DRAW_H

# include "vector2.h"
# include "color.h"
# include "image.h"
# include "rect.h"
# include "line.h"
// # include "circle.h"
void	draw_pixel(t_img *img, t_vector2 pos, int color);
// void	draw_polygon(t_img *img, t_vector2 *vertices, int num_vertices, int color);
void	draw_background(t_img *img, int color);


#endif
