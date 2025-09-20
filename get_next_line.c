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

static t_fd_node *find_or_create_fd(t_fd_list *list, int fd)
{
    t_fd_node *current = list->head;
    t_fd_node *new_node;

    while (current)
    {
        if (current->fd == fd)
            return (current);
        current = current->next;
    }
    new_node = malloc(sizeof(t_fd_node));
    if (!new_node)
        return (NULL);
    new_node->fd = fd;
    new_node->buffer = ft_strdup("");
    new_node->next = list->head;
    list->head = new_node;
    list->count++;
    if (!new_node->buffer)
    {
        free(new_node);
        return (NULL);
    }
    return (new_node);
}

static void cleanup_fd_node(t_fd_list *list, int fd)
{
    t_fd_node *current = list->head;
    t_fd_node *prev = NULL;

    while (current)
    {
        if (current->fd == fd)
        {
            if (prev)
                prev->next = current->next;
            else
                list->head = current->next;
            free(current->buffer);
            free(current);
            list->count--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

static char *extract_line(t_fd_node *node, t_fd_list *list)
{
    char *line;
    char *newline_pos;
    char *temp;
    size_t line_len;

    newline_pos = ft_strchr(node->buffer, '\n');
    if (newline_pos)
    {
        line_len = newline_pos - node->buffer + 1;
        line = ft_substr(node->buffer, 0, line_len);
        temp = ft_substr(node->buffer, line_len, ft_strlen(node->buffer) - line_len);
        free(node->buffer);
        node->buffer = temp;
        return (line);
    }
    if (ft_strlen(node->buffer) > 0)
    {
        line = ft_strdup(node->buffer);
        cleanup_fd_node(list, node->fd);
        return (line);
    }
    cleanup_fd_node(list, node->fd);
    return (NULL);
}

char *get_next_line(int fd)
{
    static t_fd_list fd_list = {NULL, 0};
    t_fd_node *node;
    char buffer[BUFFER_SIZE + 1];
    char *temp;
    ssize_t bytes_read;

    if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    node = find_or_create_fd(&fd_list, fd);
    if (!node)
        return (NULL);
    while (!ft_strchr(node->buffer, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(node->buffer, buffer);
        free(node->buffer);
        node->buffer = temp;
        if (!node->buffer)
        {
            cleanup_fd_node(&fd_list, fd);
            return (NULL);
        }
    }
    return (extract_line(node, &fd_list));
}
