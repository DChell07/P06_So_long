/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david_chellen <david_chellen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:12:06 by david_chell       #+#    #+#             */
/*   Updated: 2024/10/06 12:53:41 by david_chell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

// int main (void)
// {
//     int fd;
//     char c = 'a';
//     ft_putchar_fd(c, fd);
// 	printf("\n");
// 	return (0);
// }