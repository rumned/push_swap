/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_chunk_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 23:02:34 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 23:02:51 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pull nodes back into a, biggest index first */
void	pop_phase(t_list **a, t_list **b, t_ops *operation)
{
	int	size;

	size = stack_size(*b);
	while (size > 0)
	{
		rotate_b_to(b, operation, pos_of_index(*b, size - 1));
		pa(a, b, operation);
		size--;
	}
}
