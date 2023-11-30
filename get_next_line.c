/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:10:43 by bamssaye          #+#    #+#             */
/*   Updated: 2023/11/29 20:20:26 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *in_buffer(void)
{
    char *buffer;

    if(BUFFER_SIZE <= )
        return (NULL);
    buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buffer)
        return (NULL);
    buffer[0] = '\0';
    return (buffer);
} 
char    *get_next_line(int fd)
{
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (0);
    //static *redaer = ft_reader() ;
}