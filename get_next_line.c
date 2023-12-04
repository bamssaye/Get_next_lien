/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:10:43 by bamssaye          #+#    #+#             */
/*   Updated: 2023/12/04 05:58:58 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_getline(char *getline, char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (getline[i] && getline[i] != '\n')
		i++;
	if (getline[i] == '\n')
		i++;
	else
		return (0);
	while (getline[i])
		buffer[j++] = getline[i++];
	buffer[j] = '\0';
	getline[i - j] = '\0';
	return (1);
}

static char	*ft_free(char *getline, char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	if (*getline)
		return (getline);
	free(getline);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*getline;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	getline = ft_calloc(1, sizeof(char));
	if (!getline)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buffer && getline)
	{
		getline = ft_strjoin(getline, buffer);
		if (ft_getline(getline, buffer))
			return (getline);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (ft_free(getline, &buffer));
		buffer[bytes] = '\0';
	}
	return (NULL);
}
