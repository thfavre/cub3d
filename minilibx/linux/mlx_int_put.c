/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_int_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 23:13:06 by thomas            #+#    #+#             */
/*   Updated: 2023/07/24 23:24:00 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx_int.h"

int		mlx_int_put(t_xvar *xvar,t_win_list *win,
			       int x,int y,int color,int number)
{
   XGCValues	xgcv;
   char			string[20];

   sprintf(string, "%d", number);
   if (string == NULL)
     return (0);
   xgcv.foreground = mlx_int_get_good_color(xvar,color);
   XChangeGC(xvar->display,win->gc,GCForeground,&xgcv);
   XDrawString(xvar->display,win->window,win->gc,x,y,string,strlen(string));
   if (xvar->do_flush)
     XFlush(xvar->display);
}
