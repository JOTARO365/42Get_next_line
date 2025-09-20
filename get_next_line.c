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

t_list *create_node(char *content)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}

// Helper function to free buffer list
void free_buffer(t_list **buffer)
{
    t_list *current;
    t_list *next;

    if (!buffer || !*buffer)
        return;
    current = *buffer;
    while (current)
    {
        next = current->next;
        free(current->content);
        free(current);
        current = next;
    }
    *buffer = NULL;
}

// Helper function to read and store in buffer
void read_to_buffer(int fd, t_list **buffer)
{
    char *temp;
    t_list *new_node;
    int bytes_read;

    temp = malloc(BUFFER_SIZE + 1);
    if (!temp)
        return;
    bytes_read = read(fd, temp, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        temp[bytes_read] = '\0';
        new_node = create_node(temp);
        if (!new_node)
            return;
        if (!*buffer)
            *buffer = new_node;
        else
            ft_lstlast(*buffer)->next = new_node;
        if (ft_strchr(temp, '\n'))
            break;
        temp = malloc(BUFFER_SIZE + 1);
        if (!temp)
            return;
        bytes_read = read(fd, temp, BUFFER_SIZE);
    }
    if (bytes_read <= 0)
        free(temp);
}

// Helper function to extract line from buffer
char *extract_line(t_list **buffer)
{
    char *line = NULL;
    char *temp;
    char *newline_pos;
    char *remaining;
    t_list *first_node;

    while (*buffer)
    {
        temp = line;
        line = ft_strjoin(temp, (*buffer)->content);
        free(temp);
        newline_pos = ft_strchr((*buffer)->content, '\n');
        if (newline_pos)
        {
            remaining = ft_substr(newline_pos + 1, 0, ft_strlen(newline_pos + 1));
            first_node = *buffer;
            *buffer = (*buffer)->next;
            free(first_node->content);
            free(first_node);
            if (remaining && *remaining)
            {
                first_node = create_node(remaining);
                first_node->next = *buffer;
                *buffer = first_node;
            }
            else
                free(remaining);
            break;
        }
        first_node = *buffer;
        *buffer = (*buffer)->next;
        free(first_node->content);
        free(first_node);
    }
    if (line && ft_strchr(line, '\n'))
    {
        newline_pos = ft_strchr(line, '\n');
        *(newline_pos + 1) = '\0';
    }
    return (line);
}

// Main get_next_line function with multiple fd support
char *get_next_line(int fd)
{
    static t_list *buffers[FD_MAX];
    char *line;

    if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    read_to_buffer(fd, &buffers[fd]);
    if (!buffers[fd])
        return (NULL);
    line = extract_line(&buffers[fd]);
    if (!line)
    {
        free_buffer(&buffers[fd]);
        return (NULL);
    }
    return (line);
}	
