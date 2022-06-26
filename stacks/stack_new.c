/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:15:37 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 23:02:13 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*rtn;

	rtn = (t_stack *)malloc(sizeof(t_stack));
	if (!rtn)
		return (free (rtn), rtn = NULL);
	rtn->x = content;
	rtn->next = NULL;
	return (rtn);
}

t_stack	*ft_lstadd_front(t_stack **lst, t_stack *t_new)
{
	if (!lst || !t_new)
		return (NULL);
	if ((*lst) == NULL)
		return (t_new);
	t_new->next = *lst;
	*lst = t_new;
	return (*lst);
}

t_stack	**ft_lstadd_back(t_stack **lst, t_stack *t_new)
{
	t_stack	*t;

	if (!(*lst))
	{
		*lst = t_new;
		return (lst);
	}
	t = (*lst);
	while (t->next != NULL)
		t = t->next;
	t->next = t_new;
	t_new->next = NULL;
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

void	ft_lstdelone(t_stack *lst)
{
	t_stack	*ptr;

	if (!lst)
		return ;
	ptr = lst;
	lst = lst->next;
	ptr->next = NULL;
}
