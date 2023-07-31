/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:54:56 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 14:55:06 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
t_list	*create_lst(int *a, int n)
{
	t_list	*first;
	t_list	*t;
	t_list	*last;
	int		i;

	first = (t_list *)malloc(sizeof(t_list));
	first->content = malloc(sizeof(int));
	*(int *)first->content = a[0];
	first->next = NULL;
	last = first;
	i = 1;
	while (i < n)
	{
		t = (t_list *)malloc(sizeof(t_list));
		t->content = malloc(sizeof(int));
		*(int *)t->content = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
		i++;
	}
	return (first);
}
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst != NULL)
	{
		lst = &(*lst)->next;
	}
	*lst = new;
}

/*
int	main(void)
{
    int arr[] = {2, 22, 222, 2222, 23};
    int n = 5; 

    t_list* lst = create_lst(arr, n);

    t_list* new; 
    new = (t_list*)malloc(sizeof(t_list));
    new->content = malloc(sizeof(int));
    *(int*)new->content = 42;
    new->next = NULL;  

    ft_lstadd_back(&lst, new); 

    t_list *current = lst; 

    while (current != NULL)
    {
        printf("%d ", *(int *)current->content);
        current = current->next;
    }
    printf("\n");

    current = lst;
    while (current != NULL)
    {
        t_list *temp = current;
        current = current->next;
        free(temp->content);
        free(temp);
    }
}
*/