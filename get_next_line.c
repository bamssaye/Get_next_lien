/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:10:43 by bamssaye          #+#    #+#             */
/*   Updated: 2023/12/04 03:21:34 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	char	*ptr;
	size_t	i;

	i = 0;
	if (!nmemb || !size)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = 0;
		return (ptr);
	}
	total_size = nmemb * size;
	if (total_size / size != nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	while (i < total_size)
	{
		*((unsigned char *)ptr + i) = '\0';
		i++;
	}
	return (ptr);
}
int	ft_get_line(char *line, char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		i++;
		while (line[i])
		{
			buff[j] = line[i];
			i++;
			j++;
		}
		buff[j] = '\0';
		line[i - j] = '\0';
		return (1);
	}
	return (0);
}
char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	int			bytes_read;

	line = ft_calloc(1, sizeof(char));
	if(!line)
		return (NULL);
	if (!buff)
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buff && line)
	{
		line = ft_strjoin(line, buff);
		if (ft_get_line(line, buff))
			return (line);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buff);
			buff = NULL;
			if (line[0] != '\0')
				return (line);
			free(line);
			return (NULL);
		}
		buff[bytes_read] = '\0';
	}
	return (NULL);
}
