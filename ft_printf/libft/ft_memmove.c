/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david_chellen <david_chellen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:47:20 by david_chell       #+#    #+#             */
/*   Updated: 2024/09/23 16:35:50 by david_chell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (((char *)dest) < ((char *)src))
	{
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			((char *)dest)[len] = ((char *)src)[len];
		}
	}
	return (dest);
}

// int main (void)
// {
//     char destination[] = "Un bon poulet yassa";
//     char source[] = "poulet";
//     size_t taille = 3;
//     ft_memmove(destination + 5, source, taille);
//     printf("%s\n", destination);
//     return (0);
// }