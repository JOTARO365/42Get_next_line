/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:43:11 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/09/23 22:09:08 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

t_gnl_node	*find_fd_node(t_gnl_node **lst, int fd)
{
	t_gnl_node	*cur;

	cur = *lst;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	cur = (t_gnl_node *)malloc(sizeof(t_gnl_node));
	if (!cur)
		return (NULL);
	cur->fd = fd;
	cur->buf = NULL;
	cur->next = *lst;
	*lst = cur;
	return (cur);
}

void	remove_fd_node(t_gnl_node **lst, int fd)
{
	t_gnl_node	*prev;
	t_gnl_node	*cur;

	prev = NULL;
	cur = *lst;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (prev)
				prev->next = cur->next;
			else
				*lst = cur->next;
			free(cur->buf);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
