/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:15:37 by hameur            #+#    #+#             */
/*   Updated: 2022/06/03 19:47:24 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void ft_lstdelone(t_stack *lst)
{
	t_stack *ptr;
	
	if (!lst)
		return;
	ptr = lst;
	lst = lst->next;
	ptr->next = NULL;
	free(ptr);
}

t_stack *ft_lstdelfirst(t_stack *list)
{
	t_stack *ptr;

	if (!list)
		return(NULL);
	ptr = list;
	list = list->next;
	if (!ptr)
		free(ptr);
	return (list);
}

void ft_lstclear(t_stack **lst)
{
	t_stack *p;
	t_stack *q;

	p = *lst;
	if (!p)
		return ;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*lst = NULL;
}
void ft_lstiter(t_stack *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->x);
		lst = lst->next;
	}
}
