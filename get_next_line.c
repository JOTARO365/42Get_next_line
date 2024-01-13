/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <waon-in@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:39:01 by waon-in           #+#    #+#             */
/*   Updated: 2024/01/13 20:17:37 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[i++])
		buf[j++] = last_node->str_buf[i];
	buf[j] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char	*line_next(t_list *list)
{
	char	*next_str;
	int		str_len;

	if (list == NULL)
		return (NULL);
	str_len = len_node(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (0);
	create_list(&list, fd);
	if (list == NULL)
	{
		return (NULL);	
	}
	next_line = line_next(list);
	polish_list(&list);
	return (next_line);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int	fd;
// 	char *line;

// 	fd = open("read_error.txt",O_RDONLY);

// 	if ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("GNL : %s\n", line);
// 		free(line);
// 	}
// 	else
// 		printf("gnl = No DATA\n");
	
// 	FILE *real;

// 	real = fopen("read_error.txt","r");
	
// 	if (real != NULL )
// 	{
// 		char	buffer[BUFFER_SIZE];
// 		while (fgets(buffer, BUFFER_SIZE, real))
// 		{
// 			printf("REAL : %s\n", buffer);
// 		}
// 		fclose(real);
// 	}
	
	
	
// 	close(fd);
// 	return (0);
// }