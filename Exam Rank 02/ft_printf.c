/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:29:16 by ffrau             #+#    #+#             */
/*   Updated: 2022/02/14 18:29:34 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	nb_len(long nb, int nb_base)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= nb_base;
		count++;
	}
	return (count);
}

int	ft_atoi(int nb, char *base, int nb_base)
{
	if (nb == -2147483648)
	{
		ft_atoi((nb / nb_base), base, nb_base);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		if (nb_base != 16)
			ft_putchar('-');
		ft_atoi(nb * -1, base, nb_base);		
	}
	else
	{
		if (nb < 10)
			ft_putchar('0' + nb);
		else
		{
			ft_atoi(nb / nb_base, base, nb_base);
			ft_putchar(base[nb % nb_base]);
		}
	}
	return (nb_len(nb, nb_base));
}

int	ft_putstr(char *c)
{
	int	count;

	if (!c)
		return (ft_putstr("(null)"));
	count = 0;
	while (c[count])
		count += ft_putchar(c[count]);
	return (count);
}

int	find_types(char c, va_list list)
{
	unsigned int	x;
	char			*s;
	int				d;
	
	if (c == 'd')
		return (ft_atoi(va_arg(list, int), "0123456789", 10));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'x')
		return (ft_atoi(va_arg(list, unsigned int), "0123456789abcdef", 16));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (!s)
		return (0);
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
	return (count);
}
/*
#include <stdio.h> 
int main()
{
	printf(" - Count ft_printf: %d\n", ft_printf("Hello %s", "toto"));
	printf(" - Count printf: %d\n", printf("Hello %s", "toto"));
	printf(" - Count ft_printf: %d\n", ft_printf("%s %s", "I'm"));
	printf(" - Count printf: %d\n", printf("%s %s", "I'm"));
	printf(" - Count ft_printf: %d\n", ft_printf("Magic %s is %d", "number", 42));
	printf(" - Count printf: %d\n", printf("Magic %s is %d", "number", 42));
	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 42, 589625));
	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 42, 589625));
}*/