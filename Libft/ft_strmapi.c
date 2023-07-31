/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:11:13 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:11:15 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	change_character_at_index(unsigned int index, char c)
{
	if (index % 2 == 0)
	{
		return ('r');
	}
	return (c);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	len;
	char	*word;

	i = 0;
	len = ft_strlen(s);
	word = (char *)malloc(sizeof(char) * len + 1);
	if (!word)
	{
		free (word);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		word[i] = f(i, s[i]);
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
int main(void)
{
    char str[] = "Hello"; 
    char *final; 
    final = ft_strmapi(str, change_character_at_index); 

    printf("%s\n", final); 

    return 0; 
}
*/
