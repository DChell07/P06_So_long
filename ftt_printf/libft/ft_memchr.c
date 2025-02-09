/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david_chellen <david_chellen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:14:54 by david_chell       #+#    #+#             */
/*   Updated: 2024/08/21 11:57:58 by david_chell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int val, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char *)ptr)[i] == ((unsigned char)val))
		{
			return (((unsigned char *)ptr) + i);
		}
		i++;
	}
	return (NULL);
}

/*
int main (void)
{
	return (0);
}
*/