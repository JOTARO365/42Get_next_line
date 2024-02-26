/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:08:39 by waon-in           #+#    #+#             */
/*   Updated: 2024/02/25 01:35:06 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

typedef struct s_list
{
	char			*memo;
	struct s_list	*next;
}	t_list;

char		get_next_line(int fd);

int			len_memo(t_list *list);

t_list		*find_last_node(t_list *list);
int			get_new_line(t_list *list);

void		get_str(t_list *list, char *str);
void		create_list(t_list **list, int fd);
void		ft_append(t_list **list, char *buf);

#endif
