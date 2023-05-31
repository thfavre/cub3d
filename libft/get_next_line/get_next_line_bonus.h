/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:32:49 by fabien            #+#    #+#             */
/*   Updated: 2022/12/12 09:46:34 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct t_Node{
	char			**buffer;
	struct t_Node	*next;
}	t_Node;

char	*get_next_line(int fd);
void	stash_make(t_Node **head, int fd);
void	ft_bzero(void *s, int n);
char	*return_error(t_Node **head, int flag, char *line, int fd);

int		list_add(t_Node **head, int fd);
int		list_len(t_Node **head, int fd);
void	list_get(t_Node **head, char *line, int fd);
char	*list_free(t_Node **head, int flag, int fd);
int		enter(t_Node **head, int fd);

#endif