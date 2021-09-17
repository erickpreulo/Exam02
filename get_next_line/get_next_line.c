/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:39:00 by egomes            #+#    #+#             */
/*   Updated: 2021/09/16 18:01:16 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(char **line)
{
	int i;
	int r;
	char *buffer;
	char c;

	if (!(buffer = (char *)malloc(100000)))
		return (-1);
	i = 0;
    while (i < 100000)
        buffer[i++] = '\0';
    i = 0;
	while ((r = read(0, &c, 1)) && c != '\n' && c != '\0')
	{
        if (c == '\n' || c == '\0')
            break;
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
	}
	buffer[i] = '\0';
	*line = buffer;
	return (r);
}
