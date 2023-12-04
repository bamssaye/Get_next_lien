/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:41:40 by bamssaye          #+#    #+#             */
/*   Updated: 2023/12/04 04:30:15 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("te.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	i = 0;
	// while (i < 81)
	// {
	// 	line = get_next_line(fd);
	// 	printf("Line %d: %s", i + 1, line);
	// 	i++;
	// 	free(line);
	// }
  line = get_next_line(fd);
		printf("Line %d: %s", i + 1, line);
//   //
// 	//	i++;
		free(line);
  close(fd);
	return (0);
}