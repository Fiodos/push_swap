/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:19:32 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/06/25 11:15:13 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_duplicate(t_node *head, int n)
{
	while (head)
	{
		if (head->value == n)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		head = head->next;
	}
}

void	init_stack(int argc, char **argv, t_node **node)
{
	int		i;
	int		n;

	i = 1;
	if (argc == i)
		exit(1);
	if (argc == 2)
	{
		split_argv(argv, node);
		return ;
	}
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		is_duplicate(*node, n);
		lstadd_back(node, lstnew(n));
		i++;
	}
}

int	calc_steps(t_node *head, int max, int *rota)
{
	int	s;
	int	nodes;

	s = 0;
	nodes = count_nodes(head) / 2;
	while (head->value != max)
	{
		if (head->next == NULL)
			return (1);
		head = head->next;
		s++;
	}
	if (s > nodes)
		*rota = 0;
	else
		*rota = 1;
	if (*rota == 0)
		s = nodes - s;
	return (s);
}

void	push_first_element(t_node **head_a, t_node **head_b, int max)
{
	int	rota;

	rota = 0;
	calc_steps(*head_a, max, &rota);
	if (rota)
	{
		while ((*head_a)->value != max)
		{
			rotate(head_a);
			ft_putstr_fd("ra\n", 1);
		}
	}
	else
	{
		while ((*head_a)->value != max)
		{
			reverse_rotate(head_a);
			ft_putstr_fd("rra\n", 1);
		}
	}
	push_b(head_a, head_b);
	ft_putstr_fd("pb\n", 1);
}

void	get_range(int *scan_range, int *range, int argc)
{
	if ((argc - 1) >= 100 && (argc - 1) < 500)
	{
		*range = 20;
		*scan_range = 4;
	}
	else
	{
		*range = 40;
		*scan_range = 8;
	}
}
