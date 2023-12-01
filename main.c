/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:41:40 by bamssaye          #+#    #+#             */
/*   Updated: 2023/11/28 13:54:32 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int main()
{
	int fd;
	char *str;
	int i = 1;
	fd = open("te.txt",O_RDONLY);
	str = get_next_line(fd);
	while(i < 27)
	{
		printf("LIEN %d: %s\n",i , str[i]);
        i++;
	}
	return (0);
}