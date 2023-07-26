/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mousepressed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:58:51 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:22:41 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_mousepressed(int mousecode, int x, int y, t_data *data)
{
	data->mouse_just_pressed = true;
	data->mouse_pressed = true;
	return (0);
}
