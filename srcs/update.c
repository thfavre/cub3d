#include <stdio.h>

#include "data.h"
#include "keycodes.h"
#include "game2d.h"
#include "mlx.h"


# include <math.h>
# include "libft.h"
# include "draw.h"
#include "_time.h"

int		on_close(t_data *data);
void	on_update_utils(t_data *data);

void	raycasting(t_data *data, t_player *player, t_minimap *minimap);





void	mouse_control(t_data *data, bool *is_mouse_controled)
{
	if (data->key_just_pressed[K_E])
	{
		*is_mouse_controled = !*is_mouse_controled;
		if (*is_mouse_controled)
			mlx_mouse_hide(data->mlx, data->win);
		else
			mlx_mouse_show(data->mlx, data->win);
	}
	if (*is_mouse_controled)
	{
		if (data->mouse_pos.x != SCREEN_WIDTH / 2)
		{
			data->game2d.player.angle -= (data->mouse_pos.x - SCREEN_WIDTH / 2) * 0.3 * data->dt;
			if (data->game2d.player.angle < 0)
				data->game2d.player.angle += M_PI * 2;
			else if (data->game2d.player.angle > M_PI * 2)
				data->game2d.player.angle -= M_PI * 2;
		}
		mlx_mouse_move(data->mlx, data->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	}
}



int on_update(t_data *data)
{
	static bool is_mouse_controled = false;

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

	// mouse_control
	mouse_control(data, &is_mouse_controled);

	update_player(data, &data->game2d.player);
	raycasting(data, &data->game2d.player, &data->game2d.minimap);
	if (data->game2d.size_block.x * data->game2d.minimap.scale * data->map_mult > 3)
		draw_minimap(data, data->map, data->game2d.minimap);
	free(data->ray);

	if (is_mouse_controled)
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

void on_update_utils(t_data *data)
{
	char *str;

	if (data->key_pressed[K_ESC])
		on_close(data);
	data->dt = get_delta_time();
	mlx_mouse_get_pos(data->mlx, data->win, &data->mouse_pos.x, &data->mouse_pos.y);
	mlx_put_image_to_window(data->mlx, data->win, \
		data->img.img, 0, 0);
	ft_bzero(data->key_just_pressed, MAX_KEYS);

	data->mouse_just_pressed = false;
	draw_fps(data);
}
