/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:58:12 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 14:58:14 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* t_list	*create_lst(int *a, int n)
{
	t_list	*first;
	t_list	*t;
	t_list	*last;
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

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*
int main(void)
{
    int n = 5; 
    int arr[] = {1, 7, 15, 6, 9};

    t_list *lst = create_lst(arr, n); 

    int final; 
    final = ft_lstsize(lst); 

    printf("%d\n", final);
}
*/