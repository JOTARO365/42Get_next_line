/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:32:02 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/09/07 20:03:55 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (s == (char )c)
			return ((char )s);
		s++;
	}
	if ((char )c == '\0')
		return ((char )s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(sizeof(char ) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		res[i + j] = s2[i];
		j++;
	}
	res[j] ='\0';
	return (res);
}

gnl_node	*find_fd_node(gnl_node **lst, int fd)
{
	gnl_node	*current;

	current = *lst;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = malloc(sizeof(gnl_node));
		if (!current)
			return (NULL);
		current->fd = fd;
		current->buf = NULL;
		current->next = *lst;
		*lst = current;
		return (current);
	}
}

void	*remove_fd_node(gnl_node **lst, int fd)
{
	gnl_node	*prev;
	gnl_node	*current;

	prev = NULL;
	current = *lst;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*lst = current->next;
			free(current->buf);
			free(current);
			return ;
		}
	}
}
