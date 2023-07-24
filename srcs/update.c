#include <stdio.h>

#include "data.h"
#include "keycodes.h"
#include "draw.h"
#include "game2d.h"
#include "mlx.h"

void on_update_utils(t_data *data); // Put the function in update.c?
int	get_avrage_fps(float dt);

# include <math.h>
# include "libft.h"
# include "draw.h"

void	raycasting(t_data *data, t_player *player, t_minimap *minimap);


typedef struct s_slider
{
	t_vector2	pos;
	int			width;
	int			length;
	int			value;
}				t_slider;

bool	colide_point(t_vector2 point, t_rect rect)
{
	if (point.x >= rect.pos.x && point.x <= rect.pos.x + rect.size.x && \
		point.y >= rect.pos.y && point.y <= rect.pos.y + rect.size.y)
		return (true);
	return (false);
}

void	update_slider(t_img *img, t_vector2 mouse_pos, bool mouse_just_pressed, t_slider *slider)
{
	// slider->value goes from 0 to 1
	t_rect rect = (t_rect){slider->pos.x + slider->value * slider->length - slider->width/2, slider->pos.y - slider->width/2, slider->width, slider->width};
	if (mouse_just_pressed)
	{
		if (colide_point(mouse_pos, rect))
		{
			printf("colide\n");
		}
	}

	// draw slider
	draw_rect(img, rect, C_RED);
	// draw bar
	draw_rect(img, (t_rect){slider->pos.x, slider->pos.y-4, slider->length, 8}, C_BLACK);

}

int on_update(t_data *data)
{
	static bool in_menu;
	// draw_background(&data->img, data->textures.F);
	draw_rect(&data->img, (t_rect){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2}, data->textures.C);
	draw_rect(&data->img, (t_rect){0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2}, data->textures.F);

	// To make drop the frame rate
	if (data->key_pressed[K_T])
	{
		for (int y = 500; y < SCREEN_HEIGHT; y++)
			for (int x = 0; x < SCREEN_WIDTH; x++)
			{
				for (int i = 0; i < 3; i++)
					draw_rect(&data->img, (t_rect){x, y, 4, 4}, C_WHEAT1);
			}
	}


	// hide mouse when on window
	// if (data->mouse_pos.x >= 0 && data->mouse_pos.x < SCREEN_WIDTH && \
	// 	data->mouse_pos.y >= 0 && data->mouse_pos.y < SCREEN_HEIGHT)
	// 	mlx_mouse_hide(data->mlx, data->win);
	// else
	// 	mlx_mouse_show(data->mlx, data->win);

	// mouse center screen
	if (!in_menu)
	{
		if (data->mouse_pos.x != SCREEN_WIDTH / 2)
		{
			data->game2d.player.angle -= (data->mouse_pos.x - SCREEN_WIDTH / 2) * 0.3 * data->dt;
			if (data->game2d.player.angle < 0)
				data->game2d.player.angle += M_PI * 2;
			else if (data->game2d.player.angle > M_PI * 2)
				data->game2d.player.angle -= M_PI * 2;
		}
		mlx_mouse_move(data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	}

	// Map zoom
	if (data->key_just_pressed[K_M])
		data->game2d.minimap.scale += 0.1;

	// Door
	// if (data->key_just_pressed[K_E])
	// {
	// 	if (data->map[3][5] == 'D')
	// 		data->map[3][5] = '1';
	// 	else
	// 		data->map[3][5] = 'D';
	// }


	// Menu
	if (data->key_just_pressed[K_E])
	{
		in_menu = !in_menu;
		mlx_mouse_hide(data->mlx, data->win);

		if (in_menu)
		{
			mlx_mouse_show(data->mlx, data->win);
			printf("In menu\n");
		}
	}



	update_player(data, &data->game2d.player);
	raycasting(data, &data->game2d.player, &data->game2d.minimap);
	draw_minimap(data, data->map, data->game2d.minimap);

	// static t_slider slid = (t_slider){(t_vector2){500, 500}, 40, 100, 1};
	// update_slider(&data->img, data->mouse_pos, data->mouse_just_pressed, &slid);

	on_update_utils(data);
	// draw text
	mlx_string_put(data->mlx, data->win, 5, 15, C_WHITE, "FPS: ");

	mlx_string_put(data->mlx, data->win, 35, 15, C_WHITE, ft_itoa(get_avrage_fps(data->dt)));

}

