/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:55:54 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 14:55:58 by fszendzi         ###   ########.fr       */
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
int main(void)
{
    int arr[] = {3, 5, 7, 10, 15};
    int n = 5; 
    t_list *linked_list = create_lst(arr, n);

    t_list *new;
    new = (t_list *)malloc(sizeof(t_list));
    new->content = malloc(sizeof(int));
    *(int*)new->content = 10; 
    new->next = NULL;

    ft_lstadd_front(&linked_list, new);

    t_list *current = linked_list;
    while (current != NULL)
    {
        printf("%d ", *(int *)(current->content));
        current = current->next;
    }
    printf("\n");

    current = linked_list;
    while (current != NULL)
    {
        t_list *temp = current;
        current = current->next;
        free(temp);
    }

    return 0; 
}
*/
