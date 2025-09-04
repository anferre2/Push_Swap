/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_numb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:08:07 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/20 15:28:17 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_2num(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap('a', stack_a, stack_b);
}

void	ft_sort_3num(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first > third)
		ft_rotate('a', stack_a, stack_b);
	else if (first < second && second > third)
		ft_reverse_rotate('a', stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_swap('a', stack_a, stack_b);
}

void	ft_sort_4num(t_stack **stack_a, t_stack **stack_b)
{
	int	numb_min;

	numb_min = ft_get_min(stack_a);
	if ((*stack_a)->next->next->next->value == numb_min)
		ft_reverse_rotate('a', stack_a, stack_b);
	while ((*stack_a)->value != numb_min)
		ft_rotate('a', stack_a, stack_b);
	ft_push('b', stack_b, stack_a);
	ft_sort_3num(stack_a, stack_b);
	ft_push('a', stack_a, stack_b);
}

void	ft_sort_5num(t_stack **stack_a, t_stack **stack_b)
{
	int	to_push;
	int	len;
	int	pos;

	len = 5;
	to_push = 2;
	while (to_push > 0)
	{
		pos = ft_get_pos_min(*stack_a);
		if (pos <= len / 2)
			while (pos-- > 0)
				ft_rotate('a', stack_a, stack_b);
		else
			while (pos++ < len - 1)
				ft_reverse_rotate('a', stack_a, stack_b);
		ft_push('b', stack_b, stack_a);
		len--;
		to_push--;
	}
	ft_sort_3num(stack_a, stack_b);
	if ((*stack_b)->value < (*stack_b)->next->value)
		ft_swap('b', NULL, stack_b);
	ft_push('a', stack_a, stack_b);
	ft_push('a', stack_a, stack_b);
}

void	ft_small_numb(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		ft_sort_2num(stack_a, stack_b);
	else if (size == 3)
		ft_sort_3num(stack_a, stack_b);
	else if (size == 4)
		ft_sort_4num(stack_a, stack_b);
	else if (size == 5)
		ft_sort_5num(stack_a, stack_b);
}
