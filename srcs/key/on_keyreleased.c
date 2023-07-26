/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keyreleased.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:58:45 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:22:39 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_keyreleased(int keycode, t_data *data)
{
	if (keycode < MAX_KEYS && data->key_pressed[keycode])
		data->key_pressed[keycode] = false;
	return (0);
}
