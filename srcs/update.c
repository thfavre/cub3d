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
	float		min_value;
	float		max_value;
	float		value;
}				t_slider;

bool	colide_point(t_vector2 point, t_rect rect)
{
	if (point.x >= rect.pos.x && point.x <= rect.pos.x + rect.size.x && \
		point.y >= rect.pos.y && point.y <= rect.pos.y + rect.size.y)
		return (true);
	return (false);
}

// Easing function to smooth the slider movement
float smoothInOutQuad(float t)
{
    return t * t * (3 - 2 * t);
}

float	update_slider(t_data *data, t_slider *slider)
{
	// slider->value goes from 0 to 1
	// t_rect rect = (t_rect){slider->pos.x + slider->value * slider->length - slider->width/2, slider->pos.y - slider->width/2, slider->width, slider->width};
	t_rect hitbox_rect = (t_rect){slider->pos.x, slider->pos.y, slider->length, slider->width};
	int	slider_color = C_DARKOLIVEGREEN3;
	if (data->mouse_pressed)
	{
		if (colide_point(data->mouse_pos, hitbox_rect))
		{
			float fraction = (data->mouse_pos.x - slider->pos.x) / (float)slider->length;

            // Apply easing function to the fraction
            fraction = smoothInOutQuad(fraction);

            // Calculate the value within the specified range
            slider->value = slider->min_value + fraction * (slider->max_value - slider->min_value);
			slider_color = C_DARKOLIVEGREEN1;
			printf("slider value: %f \t (min: %f, max: %f)\n", slider->value, slider->min_value, slider->max_value);
		}
	}
	// hitbox rect
	// draw_rect(img, hitbox_rect, C_LIGHTGRAY);
	// draw bar
	int bar_height = 6;
	draw_rect(&data->img, (t_rect){slider->pos.x, slider->pos.y + slider->width/2 - bar_height/2, slider->length, bar_height}, C_BLACK);
	// draw slider
		// shadow
	draw_rect(&data->img, (t_rect){slider->pos.x + (slider->value - slider->min_value) * slider->length /  (slider->max_value - slider->min_value) - slider->width/2 -3, slider->pos.y - 3, slider->width+6, slider->width+6}, C_BLACK);
		// slider
	draw_rect(&data->img, (t_rect){slider->pos.x + (slider->value - slider->min_value) * slider->length /  (slider->max_value - slider->min_value) - slider->width/2, slider->pos.y, slider->width, slider->width}, slider_color);
	// text
	return (slider->value);
}

int on_update(t_data *data)
{
	static bool in_menu;
	// draw_background(&data->img, data->textures.F);
	draw_rect(&data->img, (t_rect){0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2 + data->walls_y_offset}, data->textures.C);
	draw_rect(&data->img, (t_rect){0, SCREEN_HEIGHT / 2 + data->walls_y_offset, SCREEN_WIDTH, SCREEN_HEIGHT / 2 - data->walls_y_offset}, data->textures.F);

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
	// if (!in_menu)
	// {
	// 	if (data->mouse_pos.x != SCREEN_WIDTH / 2)
	// 	{
	// 		data->game2d.player.angle -= (data->mouse_pos.x - SCREEN_WIDTH / 2) * 0.3 * data->dt;
	// 		if (data->game2d.player.angle < 0)
	// 			data->game2d.player.angle += M_PI * 2;
	// 		else if (data->game2d.player.angle > M_PI * 2)
	// 			data->game2d.player.angle -= M_PI * 2;
	// 	}
	// 	// mlx_mouse_move(data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); // For MAC
	// 	mlx_mouse_move(data->mlx, data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 20); // For LINUX, but dont works
	// }

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
	if (data->game2d.size_block.x * data->game2d.minimap.scale * data->map_mult > 3)
		draw_minimap(data, data->map, data->game2d.minimap);
	free(data->ray);
	//
	// Initialize the position variable

    // Initialize the slider with the position variable
    // static t_slider slid;
    // slid.pos = (t_vector2){555, 555};
    // slid.width = 40;
    // slid.length = 100;
    // slid.value = 0.54;

	static t_slider map_mult_slider = {(t_vector2){40, 300}, 40, 250, 0, MINIMAP_SIZE_RATIO, 1}; // map mult
	data->map_mult = update_slider(data, &map_mult_slider);

	// add rotate speed ?

	// add move speed ?

	static t_slider fov_slider = {(t_vector2){40, 400}, 40, 250, 1, 720, DEFAULT_FOV_DEG}; // fov
	data->fov_deg = update_slider(data, &fov_slider);

	static t_slider nb_ray_slider = {(t_vector2){40, 500}, 40, 250, 2, SCREEN_WIDTH, DEFAULT_NB_RAYS}; // nb rays
	data->nb_rays = update_slider(data, &nb_ray_slider);

	static t_slider walls_height_slider = {(t_vector2){40, 600}, 40, 250, 1, SCREEN_HEIGHT/2, 50}; // wall height
	data->walls_height = update_slider(data, &walls_height_slider);

	static t_slider walls_y_offset_slider = {(t_vector2){40, 700}, 40, 250, -SCREEN_HEIGHT/1.4, SCREEN_HEIGHT/1.4, 0}; // wall start pos
	data->walls_y_offset = update_slider(data, &walls_y_offset_slider);



	// colors, but not allowed to init the slider to the default color
	// static t_slider red_celling_color_slider = {(t_vector2){40, 700}, 20, 50, 0, 255, 50}; // red color
	// data->textures.C = set_color_red_value(data->textures.C, update_slider(data, &red_celling_color_slider));
	// static t_slider green_celling_color_slider = {(t_vector2){40+50+30, 700}, 20, 50, 0, 255, 50}; // red color
	// data->textures.C = set_color_green_value(data->textures.C, update_slider(data, &green_celling_color_slider));
	// static t_slider blue_celling_color_slider = {(t_vector2){40+50*2+30*2, 700}, 20, 50, 0, 255, 50}; // red color
	// data->textures.C = set_color_blue_value(data->textures.C, update_slider(data, &blue_celling_color_slider));



	on_update_utils(data);


}

