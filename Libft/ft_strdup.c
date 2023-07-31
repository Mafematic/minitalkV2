/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:09:29 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:09:31 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*cpy;
	size_t	i;

	len = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/*
int main(void)
{
	char str[] = "Hello";
	char *final;
	final = ft_strdup(str);
	printf("%s\n", final);
}
*/