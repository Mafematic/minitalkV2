/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:58:51 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 14:58:53 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*p;
	size_t			i;

	p = ptr;
	i = 0;
	while (i < num)
	{
		p[i] = 0;
		i++;
	}
}

/*
int main(void)
{
	char str[] = "test";
	ft_bzero(str, 2);

	int i = 0; 
	while (i < 4)
	{
		printf("%02X ", str[i]);
		i++;
	}
	printf("\n");
	return 0;
}
*/
