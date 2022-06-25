/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:48:59 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/06/25 11:13:47 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_nodes(t_node *head_a)
{
	int	i;

	i = 0;
	while (head_a != NULL)
	{
		head_a = head_a->next;
		i++;
	}
	return (i);
}

void	split_argv(char **argv, t_node **node)
{
	int		n;
	int		i;
	char	**args;

	i = 0;
	args = ft_split(argv[1], ' ');
	while (args[i])
	{
		n = ft_atoi(args[i]);
		is_duplicate(*node, n);
		lstadd_back(node, lstnew(n));
		i++;
	}
}

int	find_sec_max(t_node *head, int max)
{
	int	sec_max;

	sec_max = 0;
	while (head != NULL)
	{
		if (head->value > sec_max && head->value != max)
			sec_max = head->value;
		head = head->next;
	}
	return (sec_max);
}

void	push_and_check(t_node **head_a, t_node **head_b)
{
	push_a(head_a, head_b);
	ft_putstr_fd("pa\n", 1);
	if ((*head_a)->next != NULL)
	{
		if ((*head_a)->value > (*head_a)->next->value)
		{
			swap(head_a);
			ft_putstr_fd("sa\n", 1);
		}
	}
}

void	rotate_to_max(t_node **head_b, int max, int rota)
{
	if (rota)
	{
		while ((*head_b)->value != max)
		{
			rotate(head_b);
			ft_putstr_fd("rb\n", 1);
		}
	}
	else
	{
		while ((*head_b)->value != max)
		{
			reverse_rotate(head_b);
			ft_putstr_fd("rrb\n", 1);
		}
	}
}
