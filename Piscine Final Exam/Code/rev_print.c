/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:48:05 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/06 16:48:06 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

int		main(int ac, char **av)
{
	int	i;
	int	len;
	char	tmp;

	i = 0;
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = ft_strlen(av[1]);
	while (i < len)
	{
		tmp = av[1][i];
		av[1][i] = av[1][len];
		av[1][len] = tmp;
		i++;
		len--;
	}
	ft_putstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
