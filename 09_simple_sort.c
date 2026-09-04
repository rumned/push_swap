/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-mus <mbin-mus@student.42penang.edu    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 22:53:27 by mbin-mus          #+#    #+#             */
/*   Updated: 2026/09/04 22:50:11 by mbin-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* keep a maximal increasing run in a, push everything else to b */
static void	extract_phase(t_list **a, t_list **b, t_ops *operation)
{
	int	i;
	int	size;
	int	last;
 
	size = stack_size(*a);
	last = -1;
	i = 0;
	while (i++ < size)
	{
		if ((*a)->index > last)
		{
			last = (*a)->index;
			ra(a, operation, 1);
		}
		else
			pb(a, b, operation);
	}
}
 
void	insertion_sort(t_list **a, t_list **b, t_ops *ops);
{
	if (!a || !*a || !(*a)->next)
		return ;
	extract_phase(a, b, operation);
	if (!*b)
		return ;
	greedy_pop(a, b, operation);
}
