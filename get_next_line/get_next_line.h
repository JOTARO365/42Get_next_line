/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:08:39 by waon-in           #+#    #+#             */
/*   Updated: 2024/02/28 21:36:11 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

typedef struct s_list
{
	char			*memo;
	struct s_list	*next;
}	t_list;

char		*get_next_line(int fd);
char		*ft_next_line(t_list *list);
int			len_memo(t_list *list);

t_list		*find_last_node(t_list *list);
int			get_new_line(t_list *list);

void		get_str(t_list *list, char *str);
char		create_list(t_list **list, int fd);
void		ft_append(t_list **list, char *buf);
void		free_node(t_list **list, t_list *clean_node, char *buf);
void		list_check(t_list **list);

#endif
