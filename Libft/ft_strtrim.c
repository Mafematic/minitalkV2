/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:12:07 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:12:09 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	j = 0;
	while (is_set(set, s1[i]))
		i++;
	while (len > i && is_set(set, s1[len - 1]))
		len--;
	trimmed = (char *)malloc(sizeof(char) * (len - i) + 1);
	if (!trimmed)
		return (NULL);
	while (i < len)
	{
		trimmed[j] = s1[i];
		j++;
		i++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}

/*
int main(void)
{
	char str[] = "iiiHelloiii";
	char set[] = " ,i";	
	char *final;
	final = ft_strtrim(str, set);
	printf("%s\n", final); 
	return 0;
}
*/
