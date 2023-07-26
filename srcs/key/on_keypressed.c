/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypressed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:58:25 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:22:38 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_keypressed(int keycode, t_data *data)
{
	if (keycode < MAX_KEYS)
	{
		data->key_pressed[keycode] = true;
		data->key_just_pressed[keycode] = true;
	}
	return (0);
}
