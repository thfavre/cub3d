/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:21:48 by tastybao          #+#    #+#             */
/*   Updated: 2023/07/26 21:21:49 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "vector2.h"
# include "color.h"
# include "image.h"
# include "rect.h"
# include "line.h"
# include "data.h"
# include "gui.h"

void	draw_pixel(t_img *img, t_vector2 pos, int color);

#endif
