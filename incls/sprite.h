/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:19:57 by tastybao          #+#    #+#             */
/*   Updated: 2023/07/26 21:19:58 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "vector2.h"
# include "image.h"

typedef struct s_sprite
{
	t_vector2	size;
	t_img		img;
}				t_sprite;

#endif
