/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:10:43 by bamssaye          #+#    #+#             */
/*   Updated: 2023/11/30 22:40:29 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_content(int fd, char *buffe, char *archive)
{
	int		readlien;
	char	*tmp;

	readlien = 1;
	while (readlien)
	{
		readlien = read(fd, buffe, BUFFER_SIZE);
		if (readlien == -1)
        {

            return (0);
        }
		else if (readlien == 0)
			break ;
		buffe[readlien] = '\0';
		if (!archive)
			archive = ft_strdup("");
        tmp = archive;
		archive = ft_strjoin(tmp, buffe);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffe, '\n'))
			break ;
	}
	return (archive);
}

static char	*get_line(char *content)
{
	size_t	i;
	char	*archive;

	i = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	if (content[i] == '\0' || content[1] == '\0')
		return (0);
	archive = ft_substr(content, i + 1, ft_strlen(content) - i);
	if (!*archive)
	{
		free(archive);
		archive = NULL;
	}
	content[i + 1] = '\0';
	return (archive);
}

char	*get_next_line(int fd)
{
	char		*content;
	char		*buffe;
	static char	*archive;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffe = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffe)
		return (NULL);
	content = get_content(fd, buffe, archive);
	free(buffe);
	buffe = NULL;
	if (!content)
		return (NULL);
	archive = get_line(content);
	return (content);
}

