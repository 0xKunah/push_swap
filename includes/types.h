/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 07:21:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/12 07:21:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef TYPES_H
# define TYPES_H

# include <stddef.h>

# define PACKET_SIZE 10000

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	size_t	size_a;
	size_t	size_b;
}	t_stacks;

#endif