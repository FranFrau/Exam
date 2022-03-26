/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:34:13 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/26 19:04:38 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

void ft_putnbr_base(long long num,  char *base, int base_len)
{	
	if (num < base_len)
		write(1, &base[num], 1);
	else
	{
		ft_putnbr_base(num / base_len, base, base_len);
		ft_putnbr_base(num % base_len, base, base_len);
	}
}

int	ft_print_d(long long num)
{
	int len = 1;
	int mod = 1;
	if (num < 0)
	{
		len++;
		write (1, "-", 1);
		num *= -1;
	}
	ft_putnbr_base(num, "0123456789", 10);
	while (num / mod >= 10)
	{
		len++;
		mod *= 10;
	}
	return (len);
}

int	ft_print_x(unsigned int num)
{
	int len = 1;
	int mod = 1;
	ft_putnbr_base(num, "0123456789abcdef", 16);
	while (num / mod >= 16)
	{
		len++;
		mod *= 16;
	}
	return (len);
}

int ft_printf(char *str, ...)
{
	va_list arg;
	int	i = 0;
	int	ret = 0;

	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
				ret +=	ft_print_d(va_arg(arg, int));
			else if (str[i] == 'x')
				ret +=	ft_print_x(va_arg(arg, unsigned int));
			else if (str[i] == 's')
				ret += ft_putstr(va_arg(arg, char *));
		}
		else
			ret += write (1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (ret);
}
/*
int main ()
{
	int len;
	int len2;

	len = ft_printf("S: %s D: %d X: %x\n", "ciao", -10, 42420);
	len2= printf("S: %s D: %d X: %x\n", "ciao", -10, 42420);
	printf("MIO: %d - VERO:  %d", len, len2);
}*/