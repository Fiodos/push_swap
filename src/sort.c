/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:32:02 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/06/25 11:16:50 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_b_backwards(t_node **head_a, t_node **head_b)
{
	int	max;
	int	sec_max;
	int	control;
	int	r1;
	int	r2;

	control = 1;
	while (count_nodes(*head_b) > 0)
	{
		max = find_max(*head_b);
		sec_max = find_sec_max(*head_b, max);
		if (calc_steps(*head_b, max, &r1) > calc_steps(*head_b, sec_max, &r2)
			&& control == 1)
		{
			rotate_to_max(head_b, sec_max, r2);
			control = 0;
		}
		else
		{
			rotate_to_max(head_b, max, r1);
			control = 1;
		}
		push_and_check(head_a, head_b);
	}
}

int	get_max(t_node *head_a, int range)
{
	int	max_top;
	int	max_bot;

	max_top = find_max_top(head_a, range);
	max_bot = find_max_bot(head_a, range);
	if (max_top > max_bot)
		return (max_top);
	else
		return (max_bot);
}

int	get_bigger_element(t_node **head_a, t_node **head_b, int range)
{
	int	cmd_count;

	cmd_count = new_check_a(*head_a, *head_b);
	if (cmd_count >= 1 && cmd_count < range && count_nodes(*head_a) > range)
	{
		if (cmd_count > (count_nodes(*head_a) / 2))
		{
			while ((*head_a)->value < (*head_b)->value)
			{
				reverse_rotate(head_a);
				ft_putstr_fd("rra\n", 1);
			}
		}
		else
		{
			while (cmd_count > 1)
			{
				rotate(head_a);
				ft_putstr_fd("ra\n", 1);
				cmd_count--;
			}
		}
		return (1);
	}
	return (0);
}

void	element_found(t_node **head_a, t_node **head_b)
{
	push_b(head_a, head_b);
	ft_putstr_fd("pb\n", 1);
	if ((*head_b)->value == find_max(*head_b))
	{
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
	}
	if ((*head_b)->value > (*head_b)->next->value)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
	}
}

void	get_next_element(t_node **head_a, int scan_range)
{
	int	max_top;
	int	max_bot;

	if (count_nodes(*head_a) > scan_range)
	{
		max_top = scan_top(*head_a, scan_range);
		max_bot = scan_bot(*head_a, scan_range);
		if (max_top >= max_bot)
		{
			while ((*head_a)->value != max_top)
			{
				rotate(head_a);
				ft_putstr_fd("ra\n", 1);
			}
		}
		if (max_bot > max_top)
		{
			while ((*head_a)->value != max_bot)
			{
				reverse_rotate(head_a);
				ft_putstr_fd("rra\n", 1);
			}
		}
	}
}
