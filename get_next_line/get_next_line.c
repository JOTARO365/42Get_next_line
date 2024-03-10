/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:21:46 by waon-in           #+#    #+#             */
/*   Updated: 2024/02/28 21:35:57 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	list_check(t_list **list)
{
	t_list		*last_node;
	t_list		*clean_node;
	char		*buf;
	int			i;
	int			j;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
	{
		free_node(list, clean_node, buf);
		return ;
	}
	last_node = find_last_node(*list);
	i = 0;
	while (last_node->memo[i] && last_node->memo[i] != '\n')
		++i;
	j = 0;
	while (last_node->memo[i] && last_node->memo[++i])
		buf[j++] = last_node->memo[i];
	buf[j] = '\0';
	clean_node->memo = buf;
	clean_node->next = NULL;
	free_node(list, clean_node, buf);
}

char	*ft_next_line(t_list *list)
{
	char	*buf;
	int		len;

	if (list == NULL)
		return (NULL);
	len = len_memo(list);
	buf = malloc(len + 1);
	if (buf == NULL)
		return (NULL);
	get_str(list, buf);
	return (buf);
}

void	ft_append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	last_node = find_last_node(*list);
	if (new_node == NULL)
		return ;
	new_node->memo = buf;
	new_node->next = NULL;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
}

char	create_list(t_list **list, int fd)
{
	int		read_line;
	char	*buf;

	while (!get_new_line(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (1);
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line <= 0)
		{
			free(buf);
			if (read_line < 0)
				return (1);
			return (0);
		}
		buf[read_line] = '\0';
		ft_append(list, buf);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list		*list;
	char				*buf;
	char				err;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	err = create_list(&list, fd);
	if (err)
	{
		free_node(&list, NULL, NULL);
		return (NULL);
	}
	if (list == NULL)
		return (NULL);
	buf = ft_next_line(list);
	list_check(&list);
	return (buf);
}
