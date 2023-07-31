/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:57:24 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 14:57:26 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
t_list	*create_lst(int *a, int n)
{
	t_list	*first;
	t_list	*last;
	t_list	*t;
	int		i;

	first = (t_list *)malloc(sizeof(t_list));
	first->content = (void *)&a[0];
	first->next = NULL;
	last = first;
	i = 1;
	while (i < n)
	{
		t = (t_list *)malloc(sizeof(t_list));
		t->content = (void *)&a[i];
		t->next = NULL;
		last->next = t;
		last = t;
		i++;
	}
	return (first);
}
*/

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (NULL);
}

/*
int main(void)
{
    int arr[] = {4, 17, 2, 11, 21}; 
    int n = 5; 

    t_list *lst = create_lst(arr, n); 

    t_list *last = ft_lstlast(lst); 

    printf("%d\n", *(int*)last->content); 
}
*/