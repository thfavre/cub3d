/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:55:18 by thomas            #+#    #+#             */
/*   Updated: 2023/07/26 15:22:33 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rect.h"
#include "vector2.h"
#include <stdbool.h>

bool	collide_point(t_vector2 point, t_rect rect)
{
	if (point.x >= rect.pos.x && point.x <= rect.pos.x + rect.size.x && \
		point.y >= rect.pos.y && point.y <= rect.pos.y + rect.size.y)
		return (true);
	return (false);
}
