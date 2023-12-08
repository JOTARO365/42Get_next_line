/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <waon-in@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:09:40 by waon-in           #+#    #+#             */
/*   Updated: 2023/12/09 00:52:48 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_fd_buffer
{
	int			fd;
	char		*buffer;
	struct s_fd_buffer	*next;
}	t_fd_buffer;

static	t_fd_buffer *fd_buffers = NULL;

void	ft_free(void *ptr)
{
	if (ptr)
	{
		t_fd_buffer *current = (t_fd_buffer *)ptr;
		while (current)
		{
			t_fd_buffer *next = current->next;
			free(current->buffer);
			free(current);
			current = next;
		}
	}
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_strjoin(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*ft_get_line(char *buffer, char end_char)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != end_char)
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != end_char)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == end_char)
		line[i++] = end_char;
	line[i] = '\0';
	return (line);
}

char	*ft_get_next(char *buffer)
{
	int			i;
	int			j;
	char		*next_line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!next_line)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	free(buffer);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = NULL;
	t_fd_buffer *current = fd_buffers;
	while (current && current->fd != fd)
		current = current->next;
	if (!current)
	{
		current = (t_fd_buffer *)malloc(sizeof(t_fd_buffer));
		if (!current)
			return (NULL);
		current->fd = fd;
		current->buffer = NULL;
		current->next = fd_buffers;
		fd_buffers = current;
	}
	current->buffer = read_file(fd, current->buffer);
	if (!current->buffer)
		return (NULL);
	line = ft_get_line(current->buffer, '\n');
	current->buffer = ft_get_next(current->buffer);
	return (line);
}

// int main(void)
// {
//     int fd1 = open("file1.txt", O_RDONLY);
//     int fd2 = open("file2.txt", O_RDONLY);

//     char *line1 = get_next_line(fd1);
//     char *line2 = get_next_line(fd2);

//     // ตรวจสอบผลลัพธ์
//     if (line1)
//     {
//         printf("File 1: %s\n", line1);
//         free(line1);
//     }
//     else
//     {
//         printf("End of File 1\n");
//     }

//     if (line2)
//     {
//         printf("File 2: %s\n", line2);
//         free(line2);
//     }
//     else
//     {
//         printf("End of File 2\n");
//     }

//     close(fd1);
//     close(fd2);

//     return 0;
// }
