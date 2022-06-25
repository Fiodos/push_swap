/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:37:26 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/06/24 13:11:38 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_op(char *operation, t_node **head_a, t_node **head_b)
{
	if (!ft_strncmp("sa\n", operation, 2))
		swap(head_a);
	else if (!ft_strncmp("sb\n", operation, 2))
		swap(head_b);
	else if (!ft_strncmp("pa\n", operation, 2))
		push_a(head_a, head_b);
	else if (!ft_strncmp("pb\n", operation, 2))
		push_b(head_a, head_b);
	else if (!ft_strncmp("ra\n", operation, 2))
		rotate(head_a);
	else if (!ft_strncmp("rb\n", operation, 2))
		rotate(head_b);
	else if (!ft_strncmp("rra\n", operation, 3))
		reverse_rotate(head_a);
	else if (!ft_strncmp("rrb\n", operation, 3))
		reverse_rotate(head_b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	char	*operation;

	init_stack(argc, argv, &head_a);
	if (head_a == NULL)
		exit(1);
	operation = malloc(sizeof(char) * 5);
	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL)
			break ;
		check_op(operation, &head_a, &head_b);
	}
	if (order_a(head_a) && head_b == NULL)
		printf("OK\n");
	else
		printf("KO\n");
}
