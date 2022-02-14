/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:42:11 by ffrau             #+#    #+#             */
/*   Updated: 2022/02/14 13:39:37 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	find_types(char c, va_list list)
{
	
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += find_types(s[i + 1], list);
			i += 2;
		}
		if (!s[i])
			return (count);
		count += ft_putchar(s[i]);
		i++;
	}
}

int main(){
	ft_printf("Ciao cazz");
}