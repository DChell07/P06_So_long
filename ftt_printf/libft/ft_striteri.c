/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david_chellen <david_chellen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:42:32 by david_chell       #+#    #+#             */
/*   Updated: 2024/08/28 10:46:26 by david_chell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void big_maj(unsigned int i, char *c) 
// {
//     if (*c >= 'a' && *c <= 'z') 
// 	{
// 		*c -= 32;
//     }
//     return ;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

// int main (void)
// {
//     char line[] = "Le sprite est rose comme Buu petit";
// 	ft_striteri(line, big_maj);
//     printf("%s\n", line);
//     return (0);
// }