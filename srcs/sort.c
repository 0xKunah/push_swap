/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:57:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 14:21:04 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_stack_a(t_stacks *stacks)
{
	if (stacks->a->index == 0)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (stacks->a->index == 1)
	{
		if (stacks->a->next->index == 0)
			sa(stacks);
		else
			rra(stacks);
	}
	else
	{
		if (stacks->a->next->index)
		{
			sa(stacks);
			rra(stacks);
		}
		else
			ra(stacks);
	}
}

void	sort_three_stack_b(t_stacks *stacks)
{
	if (stacks->b->index == 0)
	{
		sb(stacks);
		rb(stacks);
	}
	else if (stacks->b->index == 1)
	{
		if (stacks->b->next->index == 0)
			sb(stacks);
		else
			rrb(stacks);
	}
	else
	{
		if (stacks->b->next->index)
		{
			sb(stacks);
			rrb(stacks);
		}
		else
			rb(stacks);
	}
}

void	sort_little_stacks(t_stacks *stacks)
{
	if (stacks->size_a == 2 && stacks->a->index)
		sa(stacks);
	else if (stacks->size_a == 3)
		sort_three_stack_a(stacks);
	else if (stacks->size_a > 3)
	{
		move_min_a_to_b(stacks);
		move_min_a_to_b(stacks);
		index_stack(&stacks->a);
		sort_little_stacks(stacks);
		if (stacks->b->value < stacks->b->next->value)
			sb(stacks);
		pa(stacks);
		pa(stacks);
	}
}

void	sort_big_stacks(t_stacks *stacks)
{
	size_t	bytes;
	size_t	i;
	size_t	size;

	i = 0;
	bytes = sizeof(int) * 8 - 1;
	while (i < bytes)
	{
		if (is_sorted(stacks->a))
			return ;
		size = stacks->size_a;
		while (size--)
		{
			if (stacks->a->index >> i & 1)
				ra(stacks);
			else
				pb(stacks);
		}
		while (stacks->b)
			pa(stacks);
		i++;
	}
}
