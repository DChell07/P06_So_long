/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:31:41 by david_chell       #+#    #+#             */
/*   Updated: 2025/01/17 22:03:58 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_letters(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*copie_le_bail(char *dest, char *src, int s, int e)
{
	int	i;

	i = 0;
	while (s < e)
	{
		dest[i] = src[s];
		i++;
		s++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*new;
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && check_letters(s1[start], set) == 1)
		start++;
	while (end > start && check_letters(s1[end - 1], set) == 1)
		end--;
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (new == NULL)
		return (NULL);
	new = copie_le_bail(new, s1, start, end);
	return (new);
}

// // enleve au debut et a la fin d un string chaque char tant que celui
// // ci se trouve dans ceux du string set
// int main (void)
// {
//     char str[] = "abcddaacedf  Bon jour   abcddaacedf";
//     char trim[] = "s ";
//     printf("%s\n", ft_strtrim(str, "abcdef"));
//     return (0);
// }