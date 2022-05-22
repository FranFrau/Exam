/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:09:08 by ffrau             #+#    #+#             */
/*   Updated: 2022/02/23 14:18:03 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_in_string(char c, char str[])
{
	int	i = 0;

	while (str[i])
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i = -1, k = 0;
	char str[256];

	if (argc != 3)
		return (write(1, "\n", 1));
	while (i < 256)
		str[i++] = '\0';
	i = 0;
	while (argv[1][i])
	{
		if (!is_in_string(argv[1][i], str))
		{
			str[k] = argv[1][i];
			write(1, &str[k], 1);
			k++;
		}
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if (!is_in_string(argv[2][i], str))
		{
			str[k] = argv[2][i];
			write(1, &str[k], 1);
			k++;
		}
		i++;
	}
	return (write(1, "\n", 1));
}
