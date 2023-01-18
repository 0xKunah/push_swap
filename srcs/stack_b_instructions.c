/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:10:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 14:25:55 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"
#include "../libft/includes/io.h"

/*  Swap the first 2 elements at the top of stack b. */
int	sb(t_stacks *stacks)
{
	int	tmp;
	int	idx;

	if (stacks->size_b < 2)
		return (0);
	tmp = stacks->b->value;
	idx = stacks->b->index;
	stacks->b->value = stacks->b->next->value;
	stacks->b->index = stacks->b->next->index;
	stacks->b->next->value = tmp;
	stacks->b->next->index = idx;
	ft_printf("sb\n");
	return (1);
}

/* Take the first element at the top of a and put it at the top of b */
int	pb(t_stacks *stacks)
{
	t_stack	*node;

	node = stacks->a;
	if (stacks->a->next)
		stacks->a->next->previous = NULL;
	stacks->size_a--;
	stacks->a = stacks->a->next;
	node->next = NULL;
	unshift_node(&stacks->b, node);
	stacks->size_b++;
	ft_printf("pb\n");
	return (1);
}

/* Shift up all elements of stack b by 1 */
int	rb(t_stacks *stacks)
{
	t_stack	*node;

	node = stacks->b;
	if (stacks->b)
		stacks->b->next->previous = NULL;
	push_node(&stacks->b, node);
	ft_printf("rb\n");
	return (1);
}

/*  Shift down all elements of stack b by 1 */
int	rrb(t_stacks *stacks)
{
	t_stack	*head;

	head = stacks->b;
	while (stacks->b->next)
		stacks->b = stacks->b->next;
	stacks->b->previous->next = NULL;
	unshift_node(&stacks->b, stacks->b);
	stacks->b = head;
	ft_printf("rrb\n");
	return (1);
}
