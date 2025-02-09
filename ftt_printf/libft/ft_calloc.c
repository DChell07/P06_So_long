/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david_chellen <david_chellen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:44:34 by david_chell       #+#    #+#             */
/*   Updated: 2024/10/04 14:04:38 by david_chell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	tot_size;
	void	*ptr;

	i = 0;
	tot_size = nmemb * size;
	ptr = malloc(tot_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < tot_size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

// int main (void)
// {
//     char *test;
//     size_t nb = 10;
//     size_t taille = 1;
//     size_t i = 0;
//     test = (char *)ft_calloc(nb, taille);
//     if (test == NULL)
//     {
//         return (0);
//     }
//     for (i = 0; i < nb; i++)
//     {
//         printf("test[%zu] = %d\n", i, (unsigned char)test[i]);
//     }
//     free(test);
//     return (0);
// }