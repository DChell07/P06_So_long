/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchellen <dchellen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:01:14 by dchellen          #+#    #+#             */
/*   Updated: 2024/10/28 14:35:30 by dchellen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_pourcent(char letter, va_list args)
{
	int	count_char;

	count_char = 0;
	if (letter == 'c' || letter == 'C')
		count_char += print_putchar_fd(va_arg(args, int), 1);
	if (letter == 's' || letter == 'S')
		count_char += print_putstr_fd(va_arg(args, char *), 1);
	if (letter == 'p' || letter == 'P')
		count_char += print_adress(va_arg(args, void *));
	if (letter == 'd' || letter == 'D' || letter == 'i' || letter == 'I')
		count_char += print_putnbr_fd(va_arg(args, int), 1);
	if (letter == 'u' || letter == 'U')
		count_char += ft_unsigned_putnbr_fd(va_arg(args, unsigned int), 1);
	if (letter == 'x')
		count_char += change_base_lowercase(va_arg(args, int), 16);
	if (letter == 'X')
		count_char += change_base_uppercase(va_arg(args, int), 16);
	if (letter == '%')
		count_char += print_putchar_fd('%', 1);
	return (count_char);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += check_pourcent(format[i], args);
			i++;
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}

// int main(void)
// {
// 	printf(" le vrais -> %d\n", printf("%X", 68435));
// 	ft_printf(" le faux  -> %d\n", ft_printf("%X", 68435));
// 	return (0);
// }
