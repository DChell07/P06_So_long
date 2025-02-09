/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchellen <dchellen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:05:48 by david_chell       #+#    #+#             */
/*   Updated: 2024/10/21 14:37:39 by dchellen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		count++;
	}
	if (n > 9)
	{
		count += print_putnbr_fd(n / 10, fd);
		n %= 10;
	}
	if (n <= 9)
	{
		n = n + 48;
		write(fd, &n, 1);
		count++;
	}
	return (count);
}

int	print_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	print_putchar_fd(char c, int fd)
{
	int	count;

	count = 0;
	count += write(fd, &c, 1);
	return (count);
}
