/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:14:28 by anferre2          #+#    #+#             */
/*   Updated: 2025/08/20 16:04:24 by anferre2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			value;
	int				index;
	struct s_stack	*next;
}	t_stack;
/*
#==============================================================================#
#                                    Errors                                     #
#==============================================================================#
*/

void	ft_exit_error(void);
void	ft_free(t_stack **stack);
void	ft_free_arguments(char **arguments);
void	ft_wrong_free(t_stack **stack_a, t_stack **stack_b, char **av, int ac);

/*
#==============================================================================#
#                                    Moves                                     #
#==============================================================================#
*/

void	ft_swap(char c, t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(char c, t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(char c, t_stack **stack_a, t_stack **stack_b);
void	ft_push(char c, t_stack **stack_to, t_stack **stack_from);

/*
#==============================================================================#
#                                    Sort                                     #
#==============================================================================#
*/

void	ft_small_numb(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_radix(t_stack **stack_a, t_stack **stack_b);

/*
#==============================================================================#
#                                    Stack                                     #
#==============================================================================#
*/

void	ft_init_stacks(t_stack ***a, t_stack ***b);
void	ft_create_stack(char **argv, t_stack **stack);
void	ft_put_first_index(t_stack **stack);

int		ft_stack_len(t_stack **stack);
t_stack	*ft_get_last(t_stack **stack);
t_stack	*ft_get_second_last(t_stack **stack);
int		ft_get_min(t_stack **stack);

int		ft_get_bits(t_stack **stack);
int		ft_get_pos_min(t_stack *a);

/*
#==============================================================================#
#                                    Utils                                     #
#==============================================================================#
*/

int		ft_only_int_check(char **argv);
int		ft_is_sorted(t_stack **stack);
int		ft_check_all(int argc, char **argv, t_stack **stack);
int		ft_is_integer(char **argv);

char	**ft_split(char const *s, char c);

int		ft_isdigit(int c);
long	ft_atol(const char *str);
int		ft_is_space(char c);

#endif