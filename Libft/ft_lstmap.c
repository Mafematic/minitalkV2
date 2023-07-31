/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fszendzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:57:39 by fszendzi          #+#    #+#             */
/*   Updated: 2023/05/17 14:57:40 by fszendzi         ###   ########.fr       */
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

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
	{
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = *lst;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}
}

void	*multiplicate_by_two(void *content)
{
	int	*new_content;

	if (content != NULL)
	{
		new_content = (int *)malloc(sizeof(int));
		*new_content = *(int *)content * 2;
		return (new_content);
	}
	return (NULL);
}

static void	del(void *content)
{
	free(content);
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first;
	void	*t;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst)
	{
		t = f(lst->content);
		first = ft_lstnew(t);
		if (!(first))
		{
			ft_lstclear(&new_lst, del);
			free(t);
			return (0);
		}
		ft_lstadd_back(&new_lst, first);
		lst = lst->next;
	}
	return (new_lst);
}
/*
int	main(void)
{
	int		n;
	t_list	*lst;
	int		i;
	t_list	*new_lst;
	int		arr[];

	arr[] = {1, 3, 4, 11, 121};
	n = 5;
	lst = create_lst(arr, n);
	t_list *head = lst; // Save the head of the list
	i = 0;
	while (i < n)
	{
		printf("%d ", *(int *)(lst->content));
		lst = lst->next;
		i++;
	}
	printf("\n");
	new_lst = ft_lstmap(head, multiplicate_by_two, del);
	i = 0;
	lst = new_lst;      // Iterate over new_lst
	while (lst != NULL) // This should be `lst != NULL` to avoid segfault
	{
		printf("%d ", *(int *)(lst->content));
		lst = lst->next;
		i++;
	}
	printf("\n");
	ft_lstclear(&head, del);
	ft_lstclear(&new_lst, del);
}
*/