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
	char		*text;
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
	int	slider_color = 0x27ae60;
	if (colide_point(data->mouse_pos, hitbox_rect))
	{
		slider_color = 0x2ecc71;
		if (data->mouse_pressed)
		{
			float fraction = (data->mouse_pos.x - slider->pos.x) / (float)slider->length;

            // Apply easing function to the fraction
            fraction = smoothInOutQuad(fraction);

            // Calculate the value within the specified range
            slider->value = slider->min_value + fraction * (slider->max_value - slider->min_value);
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
	draw_rect(&data->img, (t_rect){slider->pos.x + (slider->value - slider->min_value) * slider->length /  (slider->max_value - slider->min_value) - slider->width/2, slider->pos.y, slider->width, slider->width}, C_BLACK);
		// slider
	draw_rect(&data->img, (t_rect){slider->pos.x + (slider->value - slider->min_value) * slider->length /  (slider->max_value - slider->min_value) - slider->width/2+3, slider->pos.y+3, slider->width-6, slider->width-6}, slider_color);
	// text
	return (slider->value);
}

void	update_slider_text(t_data *data, t_slider *slider)
{
	char *text_value = ft_itoa((int)slider->value);
	if (!text_value)
		return ;
	char *text = ft_strjoin(slider->text, text_value);
	free(text_value);
	if (!text)
		return ;
	int	text_width = ft_strlen(text) * 5.85;
	int x_pos = slider->pos.x + slider->length * (slider->value - slider->min_value)/ (slider->max_value - slider->min_value) - text_width/2;
	int rect_width = text_width + 10;


	draw_rect(&data->img, (t_rect){x_pos + text_width / 2 - rect_width/2, slider->pos.y - 20, rect_width, 15}, C_WHITE);
	mlx_string_put(data->mlx, data->win, x_pos, slider->pos.y - 9, C_BLACK, text);
	free(text);
}

typedef struct s_check_box
{
	t_vector2	pos;
	int			width;
	bool		checked;
	char		*text;
}				t_check_box;

bool	update_check_box(t_data *data, t_check_box *check_box)
{
	t_rect hitbox_rect = (t_rect){check_box->pos.x, check_box->pos.y, check_box->width, check_box->width};

	int check_box_color;
	if (check_box->checked)
		check_box_color = 0x27ae60;
	else
		check_box_color = 0xc0392b;

	if (colide_point(data->mouse_pos, hitbox_rect))
	{
		if (check_box->checked)
			check_box_color = 0x2ecc71;
		else
			check_box_color = 0xe74c3c;
		if (data->mouse_just_pressed)
		{

			check_box->checked = !check_box->checked;
			printf("check_box checked: %d\n", check_box->checked);
		}
	}
	// rect
	draw_rect(&data->img, hitbox_rect, C_BLACK);
	// check_box
	draw_rect(&data->img, (t_rect){check_box->pos.x + 3, check_box->pos.y + 3, check_box->width - 6, check_box->width - 6}, check_box_color);
	return (check_box->checked);
}

void	update_check_box_text(t_data *data, t_check_box *check_box)
{
	char *text;
	if (check_box->checked)
		text = ft_strjoin(check_box->text, "ON");
	else
		text = ft_strjoin(check_box->text, "OFF");
	if (!text)
		return ;
	int text_width = ft_strlen(text) * 5.85;
	int rect_width = text_width + 10;
	int x_pos = check_box->pos.x + check_box->width / 2 - text_width / 2;


	draw_rect(&data->img, (t_rect){x_pos + text_width / 2 - rect_width/2, check_box->pos.y - 20, rect_width, 15}, C_WHITE);
	mlx_string_put(data->mlx, data->win, x_pos, check_box->pos.y - 9, C_BLACK, text);
	free(text);
}

int on_update(t_data *data)
{
	static bool mouse_control;
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


	// mouse_control
	if (data->key_just_pressed[K_E])
	{
		mouse_control = !mouse_control;

		if (mouse_control)
		{
			mlx_mouse_hide(data->mlx, data->win);
			printf("mouse_control start\n");
		}
		else
		{
			mlx_mouse_show(data->mlx, data->win);
			printf("mouse_control stop\n");
		}
	}

	if (mouse_control)
	{
		if (data->mouse_pos.x != SCREEN_WIDTH / 2)
		{
			data->game2d.player.angle -= (data->mouse_pos.x - SCREEN_WIDTH / 2) * 0.3 * data->dt;
			if (data->game2d.player.angle < 0)
				data->game2d.player.angle += M_PI * 2;
			else if (data->game2d.player.angle > M_PI * 2)
				data->game2d.player.angle -= M_PI * 2;
		}
		mlx_mouse_move(data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); // For MAC
		// mlx_mouse_move(data->mlx, data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2); // For LINUX, but dont works
	}


	update_player(data, &data->game2d.player);
	raycasting(data, &data->game2d.player, &data->game2d.minimap);
	if (data->game2d.size_block.x * data->game2d.minimap.scale * data->map_mult > 3)
		draw_minimap(data, data->map, data->game2d.minimap);
	free(data->ray);

	if (mouse_control)
	{
		int cursor_width = 20;
		int cursor_height = 4;
		int color = C_BLACK;
		int shadow_color = C_WHITE;
		draw_rect(&data->img, (t_rect){SCREEN_WIDTH / 2 - cursor_width/2, SCREEN_HEIGHT / 2 - cursor_height / 2 - 1, cursor_width, cursor_height}, shadow_color);
		draw_rect(&data->img, (t_rect){SCREEN_WIDTH / 2 - cursor_height/2-1, SCREEN_HEIGHT / 2 - cursor_width / 2-1, cursor_height, cursor_width}, shadow_color);
		draw_rect(&data->img, (t_rect){SCREEN_WIDTH / 2 - cursor_width/2, SCREEN_HEIGHT / 2 - cursor_height / 2, cursor_width, cursor_height}, color);
		draw_rect(&data->img, (t_rect){SCREEN_WIDTH / 2 - cursor_height/2, SCREEN_HEIGHT / 2 - cursor_width / 2, cursor_height, cursor_width}, color);

	}




	static t_check_box settings_box = {(t_vector2){40, 250}, 40, true, "Settings: "};
	static t_slider map_mult_slider = {(t_vector2){40, 325}, 40, 225, 0, MINIMAP_SIZE_RATIO, 1, "Minimap scale: "}; // map mult
	static t_slider fov_slider = {(t_vector2){40, 400}, 40, 225, -180, 720, DEFAULT_FOV_DEG, "FOV: "}; // fov
	static t_slider nb_ray_slider = {(t_vector2){40, 475}, 40, 225, 2, SCREEN_WIDTH, DEFAULT_NB_RAYS, "Rays nb: "}; // nb rays
	static t_slider walls_height_slider = {(t_vector2){40, 550}, 40, 225, 1, SCREEN_HEIGHT/2, DEFAULT_WALLS_HEIGHT, "Walls height: "}; // wall height
	static t_slider walls_y_offset_slider = {(t_vector2){40, 625}, 40, 225, -SCREEN_HEIGHT/1.4, SCREEN_HEIGHT/1.4, 0, "Walls y offset: "}; // wall start pos
	static t_check_box textured_box = {(t_vector2){40, 700}, 40, true, "Textures: "}; // is textured
	static t_slider untextured_color_r = {(t_vector2){100, 715}, 25, 45, 0, 255, 155, "r: "}; // untextured color
	static t_slider untextured_color_g = {(t_vector2){185, 715}, 25, 45, 0, 255, 89, "g: "}; // untextured color
	static t_slider untextured_color_b = {(t_vector2){270, 715}, 25, 45, 0, 255, 182, "b: "}; // untextured color

	static t_slider player_move_speed_slider = {(t_vector2){40, 775}, 40, 79, 0, 15, DEFAULT_PLAYER_MOVE_SPEED, "Speed: "}; // player speed
	static t_slider rotate_speed_slider = {(t_vector2){40+82+20+6 +40, 775}, 40, 77, 0, 10, DEFAULT_PLAYER_ROTATE_SPEED, "Rotation: "}; // rotate speed

	static t_check_box reset_box = {(t_vector2){40, SCREEN_HEIGHT - 60}, 40, false, "Reset: "}; // reset

	update_check_box(data, &settings_box);
	if (settings_box.checked)
	{
		data->map_mult = update_slider(data, &map_mult_slider);

		data->fov_deg = update_slider(data, &fov_slider);

		data->nb_rays = update_slider(data, &nb_ray_slider);

		data->walls_height = update_slider(data, &walls_height_slider);

		data->walls_y_offset = update_slider(data, &walls_y_offset_slider);

		data->textured = update_check_box(data, &textured_box);

		data->game2d.player.speed =  data->game2d.size_block.x * update_slider(data, &player_move_speed_slider);

		data->game2d.player.rotate_speed = update_slider(data, &rotate_speed_slider);

		if (!data->textured)
		{
			data->untextured_color = set_color_red_value(data->untextured_color, update_slider(data, &untextured_color_r));
			data->untextured_color = set_color_green_value(data->untextured_color, update_slider(data, &untextured_color_g));
			data->untextured_color = set_color_blue_value(data->untextured_color, update_slider(data, &untextured_color_b));
		}

		if (update_check_box(data, &reset_box))
		{
			fov_slider.value = DEFAULT_FOV_DEG;
			nb_ray_slider.value = DEFAULT_NB_RAYS;
			walls_height_slider.value = DEFAULT_WALLS_HEIGHT;
			walls_y_offset_slider.value = 0;
			map_mult_slider.value = 1;
			textured_box.checked = true;
			untextured_color_r.value = 155;
			untextured_color_g.value = 89;
			untextured_color_b.value = 182;
			reset_box.checked = false;
			player_move_speed_slider.value = DEFAULT_PLAYER_MOVE_SPEED;
			rotate_speed_slider.value = DEFAULT_PLAYER_ROTATE_SPEED;
		}
	}


	on_update_utils(data);

	if (settings_box.checked)
	{
		update_slider_text(data, &map_mult_slider);
		update_slider_text(data, &fov_slider);
		update_slider_text(data, &nb_ray_slider);
		update_slider_text(data, &walls_height_slider);
		update_slider_text(data, &walls_y_offset_slider);

		update_check_box_text(data, &textured_box);

		if (!data->textured)
		{
			update_slider_text(data, &untextured_color_r);
			update_slider_text(data, &untextured_color_g);
			update_slider_text(data, &untextured_color_b);
		}
		update_slider_text(data, &player_move_speed_slider);
		update_slider_text(data, &rotate_speed_slider);

		update_check_box_text(data, &reset_box);
	}
	update_check_box_text(data, &settings_box);


}

