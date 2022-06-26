/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:54:02 by hameur            #+#    #+#             */
/*   Updated: 2022/06/26 23:45:53 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_stack
{
	long int		x;
	int				index;
	struct t_stack	*next;
}	t_stack;

//____________linked list fonction____________//
t_stack	*ft_lstnew(int content);//
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstdelfirst(t_stack *list);
t_stack	*ft_lstadd_front(t_stack **lst, t_stack *t_new);//
t_stack	**ft_lstadd_back(t_stack **lst, t_stack *t_new);//
void	ft_lstclear(t_stack **lst);
void	ft_lstdelone(t_stack *lst);
int		ft_lstsize(t_stack *lst);//
/* ^^ passer list li 9bl mn li ba4i tms7*/

//__________utils___________//
void	ft_error(char *str);//
void	check_correct(t_stack **stk);//
void	clr_lst(t_stack **root, t_stack *node);//
void	check_str(char *str);//
t_stack	*initialization(t_stack *list, char *str);//
t_stack	*ft_remplissage(char *str, t_stack *list);//
int		is_digit(char str);//
int		min_stack(t_stack *s_a);//
int		checker_sortin(t_stack **s_a);//
long	int	ft_atoi(char *str);//

//_______________stacks_operations_______________//
void	rotate_a(t_stack **s_a, int i);
void	rotate_b(t_stack **s_b, int i);
void	swap_a(t_stack **stack_a, int i);
void	swap_b(t_stack **stack_b, int i);
void	r_rotate_a(t_stack **s_a, int i);
void	r_rotate_b(t_stack **s_b, int i);
void	s_swap(t_stack **s_a, t_stack **s_b);
void	r_rotate(t_stack **s_a, t_stack **s_b);
void	rr_rotate(t_stack **s_a, t_stack **s_b);
t_stack	*push_b(t_stack **s_b, t_stack **s_a, int i);
t_stack	*push_a(t_stack **s_a, t_stack **s_b, int i);

//_______________sorting_2_3_4_5_______________//
void	sort_two(t_stack **s_a);//
void	sort_three(t_stack **s_a);//
void	sort_four(t_stack **s_a, t_stack **s_b);//
void	sort_five(t_stack **s_a, t_stack **s_b);//
void	ft_sort(t_stack **s_a, t_stack **s_b, int i);//

//sort big
void	del_pos(int *ref, int index);//
void	rank_stacks(t_stack **stk, int size);//
void	ff(t_stack **s_a, t_stack **s_b, int *ref, int i);//
void	check_stack_util(t_stack **temp, long int x, int *j);
void	remplisage_a(t_stack **s_a, t_stack **s_b, int size);//
void	p_big_nd_small(int *big, int *small, int *ref, int i);//
void	push_int(t_stack **s_a, t_stack **s_b, int push, int size);//
void	remplisage_b(t_stack **s_a, t_stack **s_b, int size);//
int		max_int(t_stack *stk);//
int		*reference(int size);//

#endif