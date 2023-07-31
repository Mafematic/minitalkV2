/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:10:19 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:10:23 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dest_len)
	{
		return (size + src_len);
	}
	i = 0;
	while (dest_len + 1 + i < size && src[i])
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
int main(void)
{
	char src[] = "hello";
	char dest[] = "world";
	int size = 10;
	int n = 0;
	n = strlcat(dest, src, size);
	printf("%d\n", n);
	printf("%s\n", dest);
 	return 0;
}	
*/
