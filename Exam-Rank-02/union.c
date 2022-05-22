/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:32:25 by ffrau             #+#    #+#             */
/*   Updated: 2022/02/14 11:00:59 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int	used[255];
	int	i;
	int	j;

	if(argc != 3)
		return (write(1, "\n", 1));
	i = 1;
	while(i < 3)
	{
		j = 0;
		while(argv[i][j])
		{
			if(!used[argv[i][j]])
			{
				used[argv[i][j]] = 1;
				write(1, &argv[i][j], 1);
			}
			j++;
		}
		i++;
	}
	return (write(1, "\n", 1));
}