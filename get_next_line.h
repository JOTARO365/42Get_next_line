/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:48:03 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/09/07 20:10:22 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

#ifndef FD_MAX
#define FD_MAX 1024
#endif


typedef struct s_list
{
    char		*content;
    struct s_list *next;
} t_list;


size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
t_list *ft_lstlast(t_list *lst);

#endif
