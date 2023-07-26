/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:21:13 by tastybao          #+#    #+#             */
/*   Updated: 2023/07/26 21:21:39 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "image.h"
# include "vector2.h"

typedef struct s_line
{
	t_vector2	start_pos;
	t_vector2	end_pos;
	int			color;
	int			thickness;
}				t_line;

void	draw_line(t_img *img, t_vector2 start_pos,
			t_vector2 end_pos, int color);

#endif
