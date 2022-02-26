/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:26:31 by ffrau             #+#    #+#             */
/*   Updated: 2022/02/23 15:37:04 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i = 0;

	buffer[0] = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	a[0] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\n' || a[i] == '\0')
			break ;
		i++;
		buffer[0] = 0;
	}
	if (!a[0])
		return (NULL);
	new_a = malloc(i + 1);
	i = 0;
	while (a[i])
	{
		new_a[i] = a[i];
		i++;
	}
	new_a[i] = '\0';
	return (new_a);
}
