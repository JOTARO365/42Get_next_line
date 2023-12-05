/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waon-in <waon-in@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:58:40 by waon-in           #+#    #+#             */
/*   Updated: 2023/12/06 03:27:59 by waon-in          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int				i;
	int				j;
	int				size;
	char			*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!s1 || !s2 || !str)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str(size) = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
				return((char *)(s + i));
		i++;
	}
	if (s[i] == (char) c)
			return ((char *)(s + i));
		return (NULL);
}
