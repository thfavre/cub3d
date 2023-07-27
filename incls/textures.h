/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thfavre@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:08:36 by thomas            #+#    #+#             */
/*   Updated: 2023/07/27 01:15:26 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "image.h"

typedef struct s_textures
{
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	int		floor;
	int		celling;
}	t_textures;

#endif
