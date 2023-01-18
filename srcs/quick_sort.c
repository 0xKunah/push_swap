/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:30:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/16 14:30:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	find_min(t_stack *stack)
{
	int	min_value;
	int	pos;
	int	min_pos;

	pos = 0;
	min_value = stack->value;
	min_pos = 1;
	while (stack)
	{
		pos++;
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
	}
	return (min_pos - 1);
}

void	move_min_a_to_b(t_stacks *stacks)
{
	size_t	min;

	min = find_min(stacks->a);
	if (min <= stacks->size_a / 2)
	{
		while (min)
		{
			ra(stacks);
			min--;
		}
	}
	else
	{
		min = stacks->size_a - min;
		while (min)
		{
			rra(stacks);
			min--;
		}
	}
	pb(stacks);
}

void	quick_sort(t_stacks *stacks)
{
	while (stacks->size_a > 3)
	{
		if (is_sorted(stacks->a))
			break ;
		move_min_a_to_b(stacks);
	}
	if (!is_sorted(stacks->a))
	{
		index_stack(&stacks->a);
		sort_three_stack_a(stacks);
	}
	while (stacks->b)
		pa(stacks);
}
