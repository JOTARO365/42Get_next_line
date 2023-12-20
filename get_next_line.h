/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <waon-in@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:13:55 by waon-in           #+#    #+#             */
/*   Updated: 2023/12/20 18:07:01 by waon-in          ###   ########.fr       */
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

typedef struct s_lst
{
	char				*content;
	struct s_lst		*next;
}						t_lst;

//main
char	*get_next_line(int fd);

// utils
int		ft_found_nl(t_lst *lst);
int		ft_len_to_nl(t_lst *lst);

t_lst	*ft_find_last_node(t_lst *lst);

char	*ft_get_line(t_lst *lst);

void	ft_append(t_lst **lst, char *buf);
void	ft_check_lst(t_lst **lst);
void	ft_cpy_str(t_lst *lst, char *str);
void	ft_freelog(t_lst **lst, t_lst *clean_node, char *buf);

#endif
