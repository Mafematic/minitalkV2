/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:56:22 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 14:56:28 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	del_int(void *content)
{
	if (content != NULL)
		free(content);
}

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

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		if (del != NULL)
			del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

/*
int main(void)
{
	int arr[] = {1, 2, 4, 5, 29};
	int n = 5; 

    t_list *lst = create_lst(arr, n);
    t_list *current = lst;

    while (lst != NULL)
    {
        printf("%d ", *(int*)lst->content);
        lst = lst->next;
    }
    printf("\n");

    ft_lstclear(&lst, del_int);

    current = lst;
    while (current != NULL)
    {
        printf("%d ", *(int *)current->content);
        current = current->next;
    }
    printf("\n");

    return 0; 
}
*/