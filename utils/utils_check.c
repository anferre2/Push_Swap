/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:30:10 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/20 15:30:59 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_only_int_check(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((j == 0) && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!ft_isdigit(argv[i][j]))
			{
				ft_exit_error();
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack) || !(*stack)->next)
		return (1);
	temp = *stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_is_duplicate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next_temp;

	if (!stack || !(*stack))
		return (1);
	temp = *stack;
	while (temp->next)
	{
		next_temp = temp->next;
		while (next_temp)
		{
			if (!next_temp)
				break ;
			if (temp->value == next_temp->value)
			{
				ft_exit_error();
				return (0);
			}
			next_temp = next_temp->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_is_integer(char **argv)
{
	int		i;
	long	number;

	i = 0;
	while (argv[i])
	{
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			ft_exit_error();
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_all(int argc, char **argv, t_stack **stack)
{
	if (!ft_is_integer(argv))
		return (1);
	if (!ft_is_duplicate(stack))
		return (1);
	if (ft_is_sorted(stack))
		return (1);
	if (argc == 2)
		ft_free_arguments(argv);
	return (0);
}
