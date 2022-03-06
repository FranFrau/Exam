/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roteone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:49:13 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/06 16:50:15 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	int i;
	char tmp;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if ((av[1][i] >= 'A' && av[1][i] <= 'Y') ||
				(av[1][i] >= 'a' && av[1][i] <= 'y'))
			{
				tmp = av[1][i] + 1;
				write(1, &tmp, 1);
			}
			else if (av[1][i] == 'Z' || av[1][i] == 'z')
			{
				if (av[1][i] == 'Z')
					write(1, "A", 1);
				else
					write(1, "a", 1);
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
