/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_stacks_instructions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:10:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 11:31:52 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stacks.h"
#include "../includes/instructions.h"

/*  Both sa and sb */
int	ss(t_stacks *stacks)
{
	return (sa(stacks) && sb(stacks));
}

/*  Both ra and rb */
int	rr(t_stacks *stacks)
{
	return (ra(stacks) && rb(stacks));
}

/*  Both rra and rrb */
int	rrr(t_stacks *stacks)
{
	return (rra(stacks) && rrb(stacks));
}
