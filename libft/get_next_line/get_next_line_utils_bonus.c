/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:33:52 by fabien            #+#    #+#             */
/*   Updated: 2023/03/10 14:35:01 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* reads BUFFER_SIZE elements and adds them to a buffer
returns the value of read() or -1 if issue */
int	list_add(t_Node **head, int fd)
{
	t_Node	*new_node;
	t_Node	*current;
	int		reading;

	new_node = malloc(sizeof(t_Node));
	new_node->buffer[fd] = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new_node || !new_node->buffer[fd])
		return (-1);
	current = *head;
	new_node->next = NULL;
	reading = read(fd, new_node->buffer[fd], BUFFER_SIZE);
	if ((*head == NULL && reading == 0) || reading == -1)
	{
		free(new_node->buffer[fd]);
		free(new_node);
		return (-1);
	}
	new_node->buffer[fd][reading] = '\0';
	while (current && current->next)
		current = current->next;
	if (*head == NULL)
		*head = new_node;
	else
		current->next = new_node;
	return (reading);
}

/* returns the length of all the buffers in the linked list */
int	list_len(t_Node **head, int fd)
{
	t_Node	*current;
	int		len;
	int		i;

	len = 0;
	current = *head;
	while (current)
	{
		i = 0;
		while (current->buffer[fd][i])
		{
			if (current->buffer[fd][i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		current = current->next;
	}
	return (len);
}

/* fills res with contents of buffer in the linked lists until the \n */
void	list_get(t_Node **head, char *line, int fd)
{
	t_Node	*current;
	int		i;
	int		j;

	if (*head == NULL)
		return ;
	j = 0;
	current = *head;
	while (current != NULL)
	{
		i = 0;
		while (current->buffer[fd][i] != '\0')
		{
			line[j] = current->buffer[fd][i];
			if (current->buffer[fd][i] == '\n')
				return ;
			i++;
			j++;
		}
		current = current->next;
	}
}

/* frees the linked list entirely */
char	*list_free(t_Node **head, int flag, int fd)
{
	t_Node	*current;
	t_Node	*stock;

	stock = *head;
	while (stock != NULL)
	{
		current = stock;
		stock = stock->next;
		free(current->buffer[fd]);
		free(current);
	}
	*head = NULL;
	if (flag == 1)
		return (NULL);
	return (NULL);
}

/* returns 1 if \n in buffer, 0 otherwise */
int	enter(t_Node **head, int fd)
{
	t_Node	*current;
	int		i;

	i = 0;
	current = *head;
	if (current == NULL)
		return (0);
	while (current->next)
		current = current->next;
	while (current->buffer[fd][i])
	{
		if (current->buffer[fd][i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
