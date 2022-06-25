/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:04:38 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/06/24 13:26:21 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		scan_range;
	int		range;

	init_stack(argc, argv, &head_a);
	get_range(&scan_range, &range, argc);
	if (count_nodes(head_a) <= 5)
		sort_small_stack(&head_a, &head_b);
	if (order_a(head_a))
		return (0);
	push_first_element(&head_a, &head_b, get_max(head_a, range));
	while (count_nodes(head_a) > 0)
	{
		if (get_bigger_element(&head_a, &head_b, range))
			element_found(&head_a, &head_b);
		else
		{
			get_next_element(&head_a, scan_range);
			element_found(&head_a, &head_b);
		}
	}
	sort_b_backwards(&head_a, &head_b);
	return (0);
}
