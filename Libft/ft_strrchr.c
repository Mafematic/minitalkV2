/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:11:51 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:11:53 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = ft_strlen(s);
	ch = (unsigned char) c;
	while (i >= 0)
	{
		if (s[i] == ch)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}

/*
int main(void)
{
    char str[] = "Hello";
    int a = 'H';
    char *sol; 
    sol = ft_strrchr(str, a);
    printf("%s\n", sol);
}
*/