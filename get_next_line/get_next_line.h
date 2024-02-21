/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:08:39 by waon-in           #+#    #+#             */
/*   Updated: 2024/02/21 23:38:07 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}	t_list;

char	get_next_line(int fd);
int	len_node(t_list *list);
t_list	*find_last_node(t_list *list);

#endif
