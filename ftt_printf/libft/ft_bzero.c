/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david_chellen <david_chellen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:55:32 by david_chell       #+#    #+#             */
/*   Updated: 2024/08/26 09:39:02 by david_chell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return ;
	}
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
	return ;
}

// int main (void)
// {
// 	ft_bzero(, len);
// 	printf("%s\n", test);
// 	return (0);
// }
