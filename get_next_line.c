/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <waon-in@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:39:01 by waon-in           #+#    #+#             */
/*   Updated: 2023/12/20 18:01:12 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_check_lst(t_lst **lst)
{
	t_lst		*last_node;
	t_lst		*clean_node;
	int			i;
	int			j;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_lst));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = ft_find_last_node(*lst);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buf[j++] = last_node->content[i];
	buf[j] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	ft_freelog(lst, clean_node, buf);
}

char	*ft_get_line(t_lst *lst)
{
	int			str_len;
	char		*next_str;

	if (lst == NULL)
		return (NULL);
	str_len = ft_len_to_nl(lst);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	ft_cpy_str(lst, next_str);
	return (next_str);
}

void	ft_append(t_lst **lst, char *buf)
{
	t_lst	*new_node;
	t_lst	*last_node;

	last_node = ft_find_last_node(*lst);
	new_node = malloc(sizeof(t_lst));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	ft_read_file(t_lst **lst, int fd)
{
	int		char_read;
	char	*buf;

	while (!ft_found_nl(*lst))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (lst == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_append(lst, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_lst	*lst;
	char			*next_line;

	lst = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	ft_read_file(&lst, fd);
	if (lst == NULL)
		return (NULL);
	next_line = ft_get_line(lst);
	ft_check_lst(&lst);
	return (next_line);
}
