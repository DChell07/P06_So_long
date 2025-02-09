/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david_chellen <david_chellen@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:47:37 by david_chell       #+#    #+#             */
/*   Updated: 2024/10/04 14:33:21 by david_chell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = ft_strdup(s);
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new [i] = '\0';
	return (new);
}

// int main (void)
// {
// 	const char line[] = "Le sprite est rose comme Buu petit";
// 	printf("%s\n", ft_strmapi(line, big_maj));
//     return (0);
// }