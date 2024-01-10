/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <waon-in@student.42>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:13:55 by waon-in           #+#    #+#             */
/*   Updated: 2024/01/10 20:36:59 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char				*str_buf;
	struct s_list		*next;
}						t_list;

// MAIN
char	get_next_line(int fd);

// UNTILS
int		len_node(t_list *list);
int		*found_newline(t_list *list);

t_list	*find_last_node(t_list *list);

void	copy_str(t_list *list, char *str);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
#endif
