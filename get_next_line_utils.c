/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:10:56 by bamssaye          #+#    #+#             */
/*   Updated: 2023/11/29 20:34:35 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    if(!str)
        return (0);
    while(str[i])
    {
        i++;
    }
    return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

static char *ft_memcpy(unsigned char *dest, unsigned char *src, size_t n)
{
	size_t				i;

	i = 0;
	if (dest == src)
		return (dest);
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;
	size_t	t;

	if (!s1 && !s2)
		return (NULL);
    if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	t = ft_strlen(s2) + ft_strlen(s2) + 1;
	str = malloc(t * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
    str[ft_strlen(s2) + ft_strlen(s2)]  = '\0'; 
    free(s1);
	return (str);
}