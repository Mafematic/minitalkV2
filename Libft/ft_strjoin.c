/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:09:59 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:10:02 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*test_empty(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*joined;

	if (!s1 || !s2)
		return (test_empty(s1, s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len) + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		joined[i++] = s2[j++];
	}
	joined[i] = '\0';
	return (joined);
}

/*
int main(void)
{
	char str1[] = "Hello";
	char str2[] = "World";
	char *final;
	final = ft_strjoin(str1, str2);
	printf("%s\n", final);
	free(final);
	return 0;
}
*/
