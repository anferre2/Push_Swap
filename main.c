/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:58:29 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/20 15:53:46 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_simple_errors(char **argv, int argc)
{
	if (argc == 2)
	{
		if (argv[1][0] == '\0' || (argv[1][0] == ' ' && argv[1][1] == '\0'))
		{
			ft_exit_error();
			return (1);
		}
		if (ft_isdigit(argv[1][0]) && argv[1][1] == '\0')
			return (1);
	}
	return (0);
}

int	ft_handle_arguments(char **argv, int argc, char ***arguments)
{
	if (argc == 2)
	{
		*arguments = ft_split(argv[1], ' ');
		return (1);
	}
	else
	{
		*arguments = argv + 1;
		return (0);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_len(stack_a) <= 5)
		ft_small_numb(stack_a, stack_b, ft_stack_len(stack_a));
	else
		ft_radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**arguments;
	int		split_done;

	arguments = NULL;
	if (ft_check_simple_errors(argv, argc) == 1 || argc == 1)
		return (1);
	split_done = ft_handle_arguments(argv, argc, &arguments);
	if (!ft_only_int_check(arguments))
	{
		if (split_done == 1)
			ft_free_arguments(arguments);
		return (1);
	}
	ft_init_stacks(&stack_a, &stack_b);
	ft_create_stack(arguments, stack_a);
	if (ft_check_all(argc, arguments, stack_a))
	{
		ft_wrong_free(stack_a, stack_b, arguments, argc);
		return (1);
	}
	ft_sort(stack_a, stack_b);
	ft_wrong_free(stack_a, stack_b, arguments, argc);
	return (0);
}

/* void print_stack(const char *name, t_stack *stack)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%ld ", stack->value);
        stack = stack->next;
    }
    printf("\n");
} 
    printf("Stack final:\n");
    print_stack("A", *stack_a);
    print_stack("B", *stack_b);

*/
