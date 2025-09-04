/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:32:45 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/20 15:25:59 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*last;

	temp = *stack;
	first = (*stack)->next;
	last = ft_get_last(stack);
	last->next = temp;
	temp->next = NULL;
	*stack = first;
}

void	ft_rotate(char c, t_stack **stack_a, t_stack **stack_b)
{
	if ((c == 'a' || c == 'r') && (*stack_a) && (*stack_a)->next)
	{
		do_rotate(stack_a);
		if (c == 'a')
			write(1, "ra\n", 3);
	}
	if ((c == 'b' || c == 'r') && (*stack_b) && (*stack_b)->next)
	{
		do_rotate(stack_b);
		if (c == 'b')
			write(1, "rb\n", 3);
	}
	if (c == 'r')
		write(1, "rr\n", 3);
}

void	ft_reverse_rotate(char c, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*second_last;
	t_stack	*last;

	if ((c == 'a' || c == 'r') && (*stack_a) && (*stack_a)->next)
	{
		last = ft_get_last(stack_a);
		second_last = ft_get_second_last(stack_a);
		second_last->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		if (c == 'a')
			write(1, "rra\n", 4);
	}
	if ((c == 'b' || c == 'r') && (*stack_b) && (*stack_b)->next)
	{
		last = ft_get_last(stack_b);
		second_last = ft_get_second_last(stack_b);
		second_last->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		if (c == 'b')
			write(1, "rrb\n", 4);
	}
	if (c == 'r')
		write(1, "rrr\n", 4);
}
