/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:43:34 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/09/23 11:44:01 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_and_store(int fd, char *stash)
{
	char		*res;
	ssize_t		file;
	char		*tmp;

	file = 1;
	res = malloc(BUFFER_SIZE + 1);
	if (!res)
		return (NULL);
	while (stash == NULL || !ft_strchr(stash, '\n') && file > 0)
	{
		file = read(fd, res, BUFFER_SIZE);
		if (file == -1)
			return (free(res), free(stash), NULL);
	}
	res[file] = '\0';
	if (file > 0)
	{
		tmp = ft_strjoin(stash, res);
		free(stash);
		stash = tmp;
		if (!stash)
			return (free(res), NULL);
	}
}

char	*update_stash(char *stash)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	new	= malloc(ft_strlen(stash + i) + 1);
	if (!new)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	return (free(stash), new);
}

char	*extract_line(const char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*line;

	i = 0;
	if (!stash[i] || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	len = i + (stash[i] == '\n');
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (len > i)
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static gnl_node		*file_d;
	gnl_node			*node;
	char				*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	node = find_fd_node(&file_d, fd);
	if (!node)
		return (NULL);
	node->buf = read_and_store(fd, node->buf);
	if (!node->buf)
		return (remove_fd_node(node->buf, fd), NULL);
	line = extract_line(node->buf);
	node->buf = update_stash(node->buf);
	if (!node->buf)
		remove_fd_node(&file_d, fd);
	return (line);
}
