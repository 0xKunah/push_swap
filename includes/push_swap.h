/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 06:58:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 11:36:56 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef TYPES_H
#  include "types.h"
# endif

# include "instructions.h"
# include "stacks.h"
# include "sort.h"

void	error(void);
int		is_sorted(t_stack *stack);

#endif
