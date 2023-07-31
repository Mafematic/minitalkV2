/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:11:36 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:11:39 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_len;
	size_t	i;

	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < big_len && i + little_len <= len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
	char str1[] = "This is a sentence";
	char str2[] = "sent";

	char *final;
	final = ft_strnstr(str1, str2, 16);
	printf("%s\n", final);
}
*/