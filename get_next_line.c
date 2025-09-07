/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:01:02 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/09/07 20:50:54 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	*ft_appent_node(t_list **lst, char *res)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	last_node = ft_lstlast(*lst);
	new_node->buf = res;
	new_node->next = NULL;
	if (last_node == NULL)
		*lst = new_node;
	else
		last_node->next = new_node;
}

void	*readfile(t_list **lst, int fd)
{
	char	*res;
	ssize_t		read_line;
	
	res = malloc(BUFFER_SIZE + 1);
	if (!res)
		return (NULL);
	read_line = read(fd, res, BUFFER_SIZE);
	if (read_line <= 0)
	{
		free(res);
		if (read_line < 0)
			return (1);
		return (0);
	}
	res[read_line] = '\0';
	
}

int	get_next_line(int fd)
{
	
}