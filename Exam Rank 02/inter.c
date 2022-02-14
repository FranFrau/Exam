/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:10:50 by ffrau             #+#    #+#             */
/*   Updated: 2022/02/14 13:10:52 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;
	int	bo;

	if(argc != 3)
		return (write(1, "\n", 1));
	i = 0;
	while (argv[1][i])
	{
		j = 0;
		bo = 0;
		while (argv[2][j] && !bo)
		{
			if (argv[2][j] == argv[1][i])
			{
				k = 0;
				bo = 1;
				while (k < i)
				{
					if (argv[1][i] == argv[1][k])
						bo = 0;
					k++;
				}
				if (bo)
					write(1, &argv[1][i], 1);
			}
			j++;
		}
		i++;
	}
	return (write(1, "\n", 1));
}
