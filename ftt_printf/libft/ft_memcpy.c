/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david_chellen <david_chellen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:14:30 by david_chell       #+#    #+#             */
/*   Updated: 2024/10/04 14:32:03 by david_chell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (dest);
	}
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int main (void)
{
	char src[] = "le bruit des vagues me permet";
	char dst[100] = "";
	size_t n = 2;
	printf("%s\n", src);
	ft_memcpy(dst, src, n);
	printf("%s\n", dst);
	return (0);
}
*/