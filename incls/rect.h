/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:20:03 by tastybao          #+#    #+#             */
/*   Updated: 2023/07/26 21:20:04 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECT_H
# define RECT_H

# include "image.h"
# include "vector2.h"

typedef struct s_rect
{
	t_vector2	pos;
	t_vector2	size;
}	t_rect;

void	draw_rect(t_img *img, t_rect rect, int color);

#endif
