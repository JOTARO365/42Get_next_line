/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:32:02 by wiaon-in          #+#    #+#             */
/*   Updated: 2025/09/07 20:03:55 by wiaon-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t len = 0;
    if (!s)
        return (0);
    while (s[len])
        len++;
    return (len);
}

// ft_strchr - Locates character in string
char *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}

// ft_substr - Creates substring from string
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i = 0;
    size_t s_len;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (calloc(1, 1));
    if (len > s_len - start)
        len = s_len - start;
    substr = malloc(len + 1);
    if (!substr)
        return (NULL);
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}

// ft_strjoin - Concatenates two strings
char *ft_strjoin(char const *s1, char const *s2)
{
    char *joined;
    size_t i = 0, j = 0;
    size_t len1, len2;

    if (!s1 && !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    joined = malloc(len1 + len2 + 1);
    if (!joined)
        return (NULL);
    while (s1 && s1[i])
    {
        joined[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
        joined[i++] = s2[j++];
    joined[i] = '\0';
    return (joined);
}

// ft_strdup - Duplicates string
char *ft_strdup(const char *s)
{
    char *dup;
    size_t i = 0;
    size_t len;

    if (!s)
        return (NULL);
    len = ft_strlen(s);
    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
