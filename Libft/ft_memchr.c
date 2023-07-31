/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:06:30 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:06:32 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char) c)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
	char str[] = "Hello";
	int a = 'e'; 
	char *sol;
	int n = 4; 
	sol = ft_memchr(str, a, n); 
	printf("%s\n", sol); 
}
*/ 