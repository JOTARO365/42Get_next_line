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

char	*read_and_store(int fd, char *stash)
{
	char		*buf;
	ssize_t		br;
	char		*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	br = 1;
	while ((stash == NULL || !ft_strchr(stash, '\n')) && br > 0)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br == -1)
			return (free(buf), free(stash), NULL);
		buf[br] = '\0';
		if (br > 0)
		{
			tmp = ft_strjoin(stash, buf);
			free(stash);
			stash = tmp;
			if (!stash)
				return (free(buf), NULL);
		}
	}
	free(buf);
	return (stash);
}

char	*update_stash(char *stash)
{
	char	*new_s;
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
	new_s = (char *)malloc(ft_strlen(stash + i) + 1);
	if (!new_s)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		new_s[j++] = stash[i++];
	new_s[j] = '\0';
	free(stash);
	return (new_s);
}

char	*extract_line(const char *stash)
{
	size_t	i;
	size_t	k;
	size_t	len;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	len = i + (stash[i] == '\n');
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	k = 0;
	while (k < i)
	{
		line[k] = stash[k];
		k++;
	}
	if (len > i)
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_gnl_node	*files;
	t_gnl_node			*node;
	char				*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	node = find_fd_node(&files, fd);
	if (!node)
		return (NULL);
	node->buf = read_and_store(fd, node->buf);
	if (!node->buf)
		return (remove_fd_node(&files, fd), NULL);
	line = extract_line(node->buf);
	node->buf = update_stash(node->buf);
	if (!node->buf)
		remove_fd_node(&files, fd);
	return (line);
}
