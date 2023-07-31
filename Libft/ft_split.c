/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:08:59 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:09:02 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**counter(char const *s, char c)
{
	int		i;
	int		count;
	char	**words;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words)
		return (NULL);
	return (words);
}

static void	free_words(char **words, size_t j)
{
	while (j > 0)
		free(words[--j]);
	free(words);
}

static char	**fill_words(char **words, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[start] != c && s[start])
		{
			words[++j] = ft_substr(s, start, i - start);
			if (!words[j])
			{
				free_words(words, j);
				return (NULL);
			}
		}
	}
	words[++j] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = counter(s, c);
	if (!words)
		return (NULL);
	words = fill_words(words, s, c);
	return (words);
}

/*
int	main(void)
{
	char	c;

	char str[] = ",,,Hello,this,is,a,test,,,"; 
	c = ',';
	char **final; 
	final = ft_split(str, c);
	int i = 0; 
	while (final[i] != NULL)
	{
		printf("%s\n", final[i]);
		i++; 
	}
	return (0); 
}
*/