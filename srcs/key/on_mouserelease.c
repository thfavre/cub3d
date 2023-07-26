/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouserelease.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:58:54 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:22:41 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "keycodes.h"
#include "data.h"

int	on_mouserelease(int mousecode, int x, int y, t_data *data)
{
	data->mouse_pressed = false;
	return (0);
}
