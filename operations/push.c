/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:23:40 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/20 15:24:34 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(char c, t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*temp;
	t_stack	*receive;
	t_stack	*push;

	if (!stack_from || !*stack_from)
		return ;
	push = *stack_from;
	receive = *stack_to;
	temp = push->next;
	if (!receive)
	{
		push->next = NULL;
		*stack_to = push;
		*stack_from = temp;
	}
	else
	{
		push->next = receive;
		*stack_to = push;
		*stack_from = temp;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}
