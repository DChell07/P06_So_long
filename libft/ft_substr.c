/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:12:54 by david_chell       #+#    #+#             */
/*   Updated: 2025/01/17 22:02:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

// // copie s dans une nouvelle chaine malloc a partir de start jusqu a len
// int main (void)
// {
//     char const test[] = "Toujours au dessus comme les Kaios";
//     unsigned int debut = 0;
//     size_t taille = 8;
//     printf("%s\n", ft_substr(test, debut, taille));
//     return (0);
// }