/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:23:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 11:40:57 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/number.h"
#include "../libft/includes/io.h"
#include "../libft/includes/string.h"
#include <stdlib.h>

static int	has_duplicate(t_stack *stack, int value)
{
	stack = stack->previous;
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->previous;
	}
	return (0);
}

#include <stdio.h>

static int	parse_int(char *str)
{
	long long	n;
	int			len;
	int			i;

	len = ft_strlen(str);
	if (*str == '-' || *str == '+')
		len--;
	i = 0;
	while (str[i++] == '0')
		len--;
	n = ft_atoll(str);
	if (n > 2147483647 || n < -2147483648 || len > 10)
		error();
	return (n);
}

t_stacks	init_stacks(char **args)
{
	t_stacks	stacks;
	t_stack		*tmp;

	stacks.a = create_node(parse_int(*args));
	if (stacks.a->value == 0 && *args[0] != '0')
		error();
	stacks.b = NULL;
	stacks.size_a = 1;
	stacks.size_b = 0;
	args++;
	while (*args)
	{
		tmp = create_node(parse_int(*args));
		push_node(&(stacks.a), tmp);
		if (has_duplicate(tmp, tmp->value))
			error();
		if (tmp->value == 0 && *args[0] != '0')
			error();
		stacks.size_a++;
		args++;
	}
	return (stacks);
}
