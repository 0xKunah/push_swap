/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:10:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 14:34:25 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"
#include "../libft/includes/io.h"

/*  Swap the first 2 elements at the top of stack a. */
int	sa(t_stacks *stacks)
{
	int	tmp;
	int	idx;

	if (stacks->size_a < 2)
		return (0);
	tmp = stacks->a->value;
	idx = stacks->a->index;
	stacks->a->value = stacks->a->next->value;
	stacks->a->index = stacks->a->next->index;
	stacks->a->next->value = tmp;
	stacks->a->next->index = idx;
	ft_printf("sa\n");
	return (1);
}

/* Take the first element at the top of b and put it at the top of a */
int	pa(t_stacks *stacks)
{
	t_stack	*node;

	node = stacks->b;
	if (stacks->b->next)
		stacks->b->next->previous = NULL;
	stacks->size_b--;
	stacks->b = stacks->b->next;
	node->next = NULL;
	unshift_node(&stacks->a, node);
	stacks->size_a++;
	ft_printf("pa\n");
	return (1);
}

/* Shift up all elements of stack a by 1 */
int	ra(t_stacks *stacks)
{
	t_stack	*head;

	if (!stacks->a->next)
		return (0);
	stacks->a->next->previous = NULL;
	head = stacks->a->next;
	stacks->a->next = NULL;
	push_node(&head, stacks->a);
	stacks->a = head;
	ft_printf("ra\n");
	return (1);
}

/*  Shift down all elements of stack a by 1 */
int	rra(t_stacks *stacks)
{
	t_stack	*head;

	head = stacks->a;
	while (stacks->a->next)
		stacks->a = stacks->a->next;
	stacks->a->previous->next = NULL;
	stacks->a->previous = NULL;
	unshift_node(&head, stacks->a);
	stacks->a = head;
	ft_printf("rra\n");
	return (1);
}
