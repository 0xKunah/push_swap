/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 06:58:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 14:34:55 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/io.h"
#include "../libft/includes/memory.h"
#include "../libft/includes/string.h"
#include <stdlib.h>

// Top of a stack === Head of the list

void	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		stack->next = NULL;
		free(stack);
		stack = tmp;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**tab;

	if (argc == 1)
		return (0);
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
		tab = ++argv;
	if (*tab == NULL)
		exit (1);
	stacks = init_stacks(tab);
	if (is_sorted(stacks.a))
		exit(1);
	index_stack(&stacks.a);
	if (stacks.size_a <= 5)
		sort_little_stacks(&stacks);
	else if (stacks.size_a <= 60)
		quick_sort(&stacks);
	else
		sort_big_stacks(&stacks);
	if (argc == 2)
		ft_free_array((void **)tab);
	return (free_stack(stacks.a));
}
