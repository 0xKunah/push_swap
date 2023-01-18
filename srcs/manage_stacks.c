/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:34:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 14:39:51 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"
#include <stdlib.h>

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_stack	*get_last_node(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node && node->next)
		node = node->next;
	return (node);
}

void	push_node(t_stack **stack, t_stack *node)
{
	t_stack	*head;

	if (!(*stack))
	{
		*stack = node;
		return ;
	}
	head = *stack;
	while (*stack && (*stack)->next)
		*stack = (*stack)->next;
	node->previous = *stack;
	node->next = NULL;
	(*stack)->next = node;
	*stack = head;
}

void	unshift_node(t_stack **stack, t_stack *node)
{
	if (!(*stack))
	{
		*stack = node;
		return ;
	}
	node->next = *stack;
	(*stack)->previous = node;
	(*stack) = node;
}
