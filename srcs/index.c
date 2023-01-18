/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:33:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 09:33:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"

int	get_index(t_stack *stack, int value)
{
	int	idx;

	idx = 0;
	while (stack)
	{
		if (stack->value < value)
			idx++;
		stack = stack->next;
	}
	return (idx);
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (*stack)
	{
		(*stack)->index = get_index(head, ((*stack)->value));
		*stack = (*stack)->next;
	}
	*stack = head;
}
