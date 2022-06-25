/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:27:42 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/06/25 11:08:32 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	new_check_a(t_node *head_a, t_node *head_b)
{
	int	nodes_a;
	int	i;

	nodes_a = count_nodes(head_a);
	i = 1;
	while (i != nodes_a)
	{
		if (head_a->next == NULL)
			return (0);
		if (head_a->value > head_b->value)
			return (i);
		head_a = head_a->next;
		i++;
	}
	return (0);
}

int	order_a(t_node *head_a)
{
	int	control;
	int	count;

	control = 0;
	count = 0;
	if (head_a == NULL)
		return (control);
	while (head_a->next != NULL)
	{
		if ((head_a->value) < (head_a->next->value))
		{
			head_a = head_a->next;
			count++;
		}
		else
			return (control);
	}
	control = 1;
	return (control);
}

void	check_a(t_node **head_a)
{
	if ((*head_a)->value == find_max(*head_a))
	{
		rotate(head_a);
		ft_putstr_fd("ra\n", 1);
	}
	if ((*head_a)->next->value == find_max(*head_a))
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
		rotate(head_a);
		ft_putstr_fd("ra\n", 1);
	}
	if ((*head_a)->value > (*head_a)->next->value)
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (lstlast(*head_a)->value < (*head_a)->value)
	{
		reverse_rotate(head_a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	check_b_reverse(t_node **head_a, t_node **head_b)
{
	if ((*head_a) == NULL || (*head_a)->next == NULL)
	{
		push_a(head_a, head_b);
		ft_putstr_fd("pa\n", 1);
		return ;
	}
	else if ((*head_b)->next == NULL)
	{
		push_a(head_a, head_b);
		ft_putstr_fd("pa\n", 1);
		return ;
	}
	else if ((*head_b)->value < (*head_b)->next->value)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
	}
	push_a(head_a, head_b);
	ft_putstr_fd("pa\n", 1);
}

void	sort_small_stack(t_node **head_a, t_node **head_b)
{
	while (!order_a(*head_a))
	{
		check_a(head_a);
		if (!order_a(*head_a))
		{
			push_b(head_a, head_b);
			ft_putstr_fd("pb\n", 1);
		}
	}
	while (count_nodes(*head_b) != 0)
	{
		check_b_reverse(head_a, head_b);
		if ((*head_a)->value > (*head_a)->next->value)
		{
			swap(head_a);
			ft_putstr_fd("sa\n", 1);
		}
	}
}
