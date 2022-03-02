/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:34:13 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/02 12:58:33 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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

int	ft_atoi(long long nb, char *base, int nb_base)
{
	int	count;

	count = 0;
	if (nb == -2147483648 && nb_base == 10)
		return (ft_putstr("-2147483648"));
	else if (nb < 0)
	{
		if (nb_base != 16)
			count += ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		return (count += ft_putchar('0' + nb));
	if (nb / nb_base > 0)
		count += ft_atoi(nb / nb_base, base, nb_base);
	count += ft_putchar(base[nb % nb_base]);
	return (count);
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
			i++;
			if (s[i] == 'd')
				count += ft_atoi(va_arg(list, int), "0123456789", 10);
			else if (s[i] == 's')
				count += ft_putstr(va_arg(list, char *)));
			else if (s[i] == 'x')
				count += ft_atoi(va_arg(list, unsigned int), "0123456789abcdef", 16);
			i++;
		}
		if (!s[i])
			return (count);
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

// #include <stdio.h> 
// int main()
// {
// 	printf(" - Count ft_printf: %d\n", ft_printf("Hello %s", "toto"));
// 	printf(" - Count printf: %d\n", printf("Hello %s", "toto"));
// 	printf(" - Count ft_printf: %d\n", ft_printf("%s %s", "I'm"));
// 	printf(" - Count printf: %d\n", printf("%s %s", "I'm"));
// 	printf(" - Count ft_printf: %d\n", ft_printf("Magic %s is %d", "number", 42));
// 	printf(" - Count printf: %d\n", printf("Magic %s is %d", "number", 42));
// 	printf(" - Count ft_printf: %d\n", ft_printf("Hexadecimal for %d is %x", 42, 589625));
// 	printf(" - Count printf: %d\n", printf("Hexadecimal for %d is %x", 42, 589625));
// }