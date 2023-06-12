#include <stdbool.h>
#include <stdlib.h>

#include "vector2.h"
#include "image.h"
#include "draw.h"


void	draw_line_step(t_img *img, t_vector2 *pos, t_vector2 *d, t_vector2 *s, int *err, int color, int thickness) {
	t_rect rect = {{pos->x - thickness / 2, pos->y - thickness / 2}, {thickness, thickness}};
	draw_rect(img, rect, color);

	int e2 = 2 * *err;
	if (e2 > -d->y) {
		*err -= d->y;
		pos->x += s->x;
	}
	if (e2 < d->x) {
		*err += d->x;
		pos->y += s->y;
	}
}
// TODO normeinettiser this function
void	draw_line(t_img *img, t_vector2 start_pos, t_vector2 end_pos, int color, int thickness) {
	t_vector2 d = {abs(end_pos.x - start_pos.x), abs(end_pos.y - start_pos.y)};
	t_vector2 s = {(start_pos.x < end_pos.x) ? 1 : -1, (start_pos.y < end_pos.y) ? 1 : -1};
	t_vector2 pos = start_pos;
	int err = d.x - d.y;

	while (true) {
		draw_line_step(img, &pos, &d, &s, &err, color, thickness);
		if (pos.x == end_pos.x && pos.y == end_pos.y) break;
	}
}
