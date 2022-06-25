/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:24:27 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/06/24 13:26:21 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	scan_top(t_node *head, int scan_range)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	if (count_nodes(head) == 1)
		return (head->value);
	while (i < scan_range)
	{
		if (head->next == NULL)
			return (max);
		if (head->value > max)
			max = head->value;
		head = head->next;
		i++;
	}
	return (max);
}

int	scan_bot(t_node *head, int scan_range)
{
	int	i;
	int	max;
	int	nodes;

	i = 0;
	nodes = count_nodes(head);
	while (i < nodes - scan_range)
	{
		if (head->next == NULL)
			return (0);
		head = head->next;
		i++;
	}
	i = 0;
	max = 0;
	while (i < scan_range)
	{
		if (head->next == NULL)
			return (max);
		if (head->value > max)
			max = head->value;
		head = head->next;
		i++;
	}
	return (max);
}

int	find_max_top(t_node *head, int range)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < range)
	{
		if (head->next == NULL)
			return (max);
		if (head->value > max)
			max = head->value;
		head = head->next;
		i++;
	}
	return (max);
}

int	find_max_bot(t_node *head, int range)
{
	int	i;
	int	max;
	int	nodes;

	i = 0;
	nodes = count_nodes(head);
	while (i < (nodes - range))
	{
		if (head->next == NULL)
			return (0);
		head = head->next;
		i++;
	}
	i = 0;
	max = 0;
	while (i < range)
	{
		if (head->next == NULL)
			return (max);
		if (head->value > max)
			max = head->value;
		head = head->next;
		i++;
	}
	return (max);
}

int	find_max(t_node *head)
{
	int	max;

	max = 0;
	while (head != NULL)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
	}
	return (max);
}
