/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:11:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 11:26:14 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# ifndef TYPES_H
#  include "types.h"
# endif

/* === Require at least 2 elements === */
/*  Swap the first 2 elements at the top of stack a. */
int	sa(t_stacks *stacks);
/*  Swap the first 2 elements at the top of stack b. */
int	sb(t_stacks *stacks);
/*  Both sa and sb */
int	ss(t_stacks *stacks);

/* === Require at least 1 element === */
/* Take the first element at the top of b and put it at the top of a */
int	pa(t_stacks *stacks);
/* Take the first element at the top of a and put it at the top of b */
int	pb(t_stacks *stacks);

/* Shift up all elements of stack a by 1 */
int	ra(t_stacks *stacks);
/* Shift up all elements of stack b by 1 */
int	rb(t_stacks *stacks);
/*  Both ra and rb */
int	rr(t_stacks *stacks);

/*  Shift down all elements of stack a by 1 */
int	rra(t_stacks *stacks);
/*  Shift down all elements of stack b by 1 */
int	rrb(t_stacks *stacks);
/*  Both rra and rrb */
int	rrr(t_stacks *stacks);

#endif
