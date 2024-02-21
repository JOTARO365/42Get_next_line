/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:47:20 by waon-in           #+#    #+#             */
/*   Updated: 2024/02/22 00:50:27 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_buffer(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	if (list->buffer == NULL)
		return (NULL);
	return (list);
}

int	main()
{
	t_list node1,node2,node3;

	node1.buffer = "test\n";
	node1.next = &node2;
	node2.buffer = "for\n";
	node2.next = &node3;
	node3.buffer = "function\n";
	node3.next = NULL;

	t_list *last_node = find_last_node(&node1);

	if (last_node != NULL)
	{
		printf("test function find_last_node\n");
		printf("data last node : %s\n",last_node->buffer);
	}
	else
	{
		printf("test function find_last_node\n");
		printf("data last node is NULL\n");
	}
	printf("test function len_node : %d\n",len_buffer(&node1));
	return (0);
}
