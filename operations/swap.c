/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:11:30 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/20 15:23:56 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(char c, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		temp_index;

	if ((c == 'a') && ft_stack_len(stack_a) >= 2)
	{
		temp = *stack_a;
		temp_index = (*stack_a)->index;
		(*stack_a)->value = (*stack_a)->next->value;
		(*stack_a)->index = (*stack_a)->next->index;
		(*stack_a)->next->value = temp->value;
		(*stack_a)->next->index = temp_index;
		write(1, "sa\n", 3);
	}
	if ((c == 'b') && ft_stack_len(stack_b) >= 2)
	{
		temp = *stack_b;
		temp_index = (*stack_b)->index;
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->index = (*stack_b)->next->index;
		(*stack_b)->next->value = temp->value;
		(*stack_b)->next->index = temp_index;
		write(1, "sb\n", 3);
	}
}
