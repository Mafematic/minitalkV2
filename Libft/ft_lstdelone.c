/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:56:47 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 14:56:48 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	del(void *content)
{
	free(content);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	if (del != NULL)
		del(lst->content);
	free(lst);
	lst = NULL;
}

/*
int	main(void)
{
	t_list *new;
	new = (t_list*)malloc(sizeof(t_list));
	new->content = malloc(sizeof(int));
	*(int *)new->content = 10;
	new->next = NULL; 
    printf("%d\n", *(int*)new->content);
    ft_lstdelone(new, del);
    printf("%d\n", *(int *)new->content);
}
*/
