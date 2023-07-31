/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:09:44 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:09:46 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	change_character(unsigned int index, char *s)
{
	if (index % 2 == 0 && *s >= 'a' && *s <= 'z')
	{
		*s -= 32;
	}
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
int main(void)
{
    char str[] = "Hello"; 
    ft_striteri(str, change_character); 

    printf("%s\n", str); 
    return 0; 
}
*/