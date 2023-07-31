/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:57:04 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 14:57:07 by fszendzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
t_list	*create_lst(int *arr, int n)
{
	t_list	*first;
	t_list	*t;
	t_list	*last;
	int		i;

	first = (t_list *)malloc(sizeof(t_list));
	first->content = malloc(sizeof(int));
	*(int *)first->content = arr[0];
	first->next = NULL;
	last = first;
	i = 1;
	while (i < n)
	{
		t = (t_list *)malloc(sizeof(t_list));
		t->content = malloc(sizeof(int));
		*(int *)t->content = arr[i];
		t->next = NULL;
		last->next = t;
		last = t;
		i++;
	}
	return (first);
}

void	add_two(void *content)
{
	if (content != NULL)
	{
		*(int *)content += 2;
	}
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
int main(void)
{
    int arr[] = {2, 4, 6, 7, 11}; 
    int n = 5; 

    t_list *lst = create_lst(arr, n); 
    t_list *current = lst; 

    while (current != NULL)
    {
        printf("%d ", *(int*)current->content);
        current = current->next; 
    }
    printf("\n"); 

    current = lst; 
    ft_lstiter(current, add_two);

    while (current != NULL)
    {
        printf("%d ", *(int *)current->content);
        current = current->next;
    }
    printf("\n");

    return 0; 
}
*/