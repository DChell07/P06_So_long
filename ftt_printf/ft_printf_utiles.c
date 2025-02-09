/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchellen <dchellen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:30:41 by dchellen          #+#    #+#             */
/*   Updated: 2024/10/21 14:00:28 by dchellen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	change_base_uppercase(unsigned int nb, unsigned int base)
{
	char	new;
	int		count;

	count = 0;
	if (nb >= base)
	{
		count += change_base_uppercase(nb / base, base);
		if ((nb % base) < 10)
			new = (nb % base) + 48;
		else
			new = (nb % base) - 10 + 65;
		write(1, &new, 1);
		count ++;
	}
	if (nb < base)
	{
		if (nb < 10)
			new = nb + 48;
		else
			new = nb - 10 + 65;
		write(1, &new, 1);
		count ++;
	}
	return (count);
}

int	change_base_lowercase(unsigned int nb, unsigned int base)
{
	char	new;
	int		count;

	count = 0;
	if (nb >= base)
	{
		count += change_base_lowercase(nb / base, base);
		if ((nb % base) < 10)
			new = (nb % base) + 48;
		else
			new = (nb % base) - 10 + 97;
		write(1, &new, 1);
		count++;
	}
	if (nb < base)
	{
		if (nb < 10)
			new = nb + 48;
		else
			new = nb - 10 + 97;
		write(1, &new, 1);
		count++;
	}
	return (count);
}

int	change_base_adress(unsigned long int nb, unsigned long int base)
{
	char	new;
	int		count;

	count = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb >= base)
		count += change_base_adress(nb / base, base);
	if (nb % base < 10)
		new = (nb % base) + '0';
	else
		new = (nb % base) - 10 + 'a';
	write(1, &new, 1);
	count++;
	return (count);
}

int	ft_unsigned_putnbr_fd(unsigned int nb, unsigned long fd)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_unsigned_putnbr_fd(nb / 10, fd);
		nb %= 10;
	}
	if (nb <= 9)
	{
		nb = nb + 48;
		write(fd, &nb, 1);
		count++;
	}
	return (count);
}

int	print_adress(void *ptr)
{
	unsigned long int	adress;
	int					count;

	adress = (unsigned long int)ptr;
	count = 0;
	write(1, "0x", 2);
	count += 2;
	count += change_base_adress(adress, 16);
	return (count);
}
