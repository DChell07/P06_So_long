/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david_chellen <david_chellen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 10:40:11 by david_chell       #+#    #+#             */
/*   Updated: 2024/08/21 11:12:58 by david_chell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[j])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[j]);
		}
		i++;
		j++;
	}
	return (0);
}

/*
int main (void)
{
	char *str1 = "abcde";
	char *str2 = "arcdz";
	size_t taille = 3;
	printf("%d\n", ft_memcmp(str1, str2, taille));
	return (0);
}
*/