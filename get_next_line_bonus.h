/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:42:27 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/09/23 18:57:22 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

typedef struct s_gnl_node
{
	int						fd;
	char					*buf;
	struct s_gnl_node		*next;
}	t_gnl_node;

char		*get_next_line(int fd);
t_gnl_node	*find_fd_node(t_gnl_node **lst, int fd);
size_t		ft_strlen(const char *s);
void		remove_fd_node(t_gnl_node **lst, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
