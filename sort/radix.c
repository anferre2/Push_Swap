/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:12:45 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/21 11:56:30 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_bits(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		bits;

	temp = *stack;
	max = temp->index;
	bits = 0;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int		max_bits;
	int		bits;
	int		i;
	int		stack_size;
	t_stack	*temp;

	bits = -1;
	i = 0;
	stack_size = ft_stack_len(stack_a);
	ft_put_first_index(stack_a);
	max_bits = ft_get_bits(stack_a);
	while (!ft_is_sorted(stack_a) && ++bits < max_bits)
	{
		i = 0;
		while (i++ < stack_size)
		{
			temp = *stack_a;
			if (((temp->index >> bits) & 1) == 1)
				ft_rotate('a', stack_a, stack_b);
			else
				ft_push('b', stack_b, stack_a);
		}
		while (*stack_b)
			ft_push('a', stack_a, stack_b);
	}
}
