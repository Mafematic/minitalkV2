/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:14 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 15:07:16 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	if (!destination && !source)
		return (NULL);
	dest = destination;
	src = source;
	i = 0;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}

/* 
int main(void)
{
	char src[] = "test";
	char dest[] = "foo"; 
	ft_memcpy(dest, &src[2], 2); 
	printf("%s\n", dest);

	char src1[] = "test";
	char dest1[] = "foo";
	memcpy(dest1, &src1[2], 2);
	printf("%s\n", dest1);

	char *src3 = NULL;
	char dst3[] = "foo";
	memcpy(dst3, src3, 2);
	printf("%s\n", dst3);

	char *src4 = NULL; 
	char dst4[] = "foo";
	ft_memcpy(dst4, src4, 2);
	printf("%s\n", dst4);

	return 0;
}
*/