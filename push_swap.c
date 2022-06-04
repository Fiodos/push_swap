/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:04:38 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/06/04 18:16:39 by fyuzhyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

typedef	struct t_nodes
{
	int	value;
	struct t_nodes *next;
} t_node;

t_node	*lstnew(int n)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == 0)
		return (0);
	new_node->value = n;
	new_node->next = NULL;
	return (new_node);
}

t_node	*lstlast(t_node *lst)
{
	t_node	*curr;

	curr = lst;
	if (curr == 0)
		return (curr);
	while (curr->next != 0)
		curr = curr->next;
	return (curr);
}

t_node	*lst_second_last(t_node *lst)
{
	t_node	*curr;

	curr = lst;
	if (curr == 0)
		return (curr);
	while (curr->next->next != NULL)
		curr = curr->next;
	return (curr);
}

void	lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (*lst == 0)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
	new = lstlast(new);
	new->next = NULL;
}

void	rotate(t_node **head)
{
	t_node	*new_head;
	t_node	*last;

	last = lstlast(*head);
	new_head = (*head)->next;
	(*head)->next = NULL;
	last->next = *head;
	*head = new_head;
}

void	reverse_rotate(t_node **head)
{
	t_node	*last;
	t_node	*second_last;

	last = lstlast(*head);
	second_last = lst_second_last(*head);
	last->next = *head;
	*head = last;
	second_last->next = NULL;
}

void	swap(t_node **head)
{
	t_node	*new_head;

	new_head = (*head)->next;
	(*head)->next = new_head->next;
	new_head->next = *head;
	*head = new_head;
}

void	push_a(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	tmp = (*head_b)->next;
	if ((*head_a) == NULL)
	{
		(*head_a) = (*head_b);
		(*head_a)->next = NULL;
	}
	else
		lstadd_front(head_a, *(head_b));
	(*head_b) = tmp;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	tmp = (*head_a)->next;
	if ((*head_b) == NULL)
	{
		(*head_b) = (*head_a);
		(*head_b)->next = NULL;
	}
	else
		lstadd_front(head_b, *(head_a));
	(*head_a) = tmp;
	ft_putstr_fd("pb\n", 1);
}

void	init_stack(int argc, char **argv, t_node **node)
{
	int	i;
	int	n;

	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		lstadd_back(node, lstnew(n));
		i++;
	}
}

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

int	find_max(t_node *head)
{
	int	max;

	max = 0;
	while(head != 0)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
	}
	return (max);
}

int	scan_top(t_node *head)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	if (count_nodes(head) == 1)
		return (head->value);
	while(i < 10)
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


int	scan_bot(t_node *head)
{
	int	i;
	int	max;
	int	nodes;

	i = 0;
	nodes = count_nodes(head);
	while (i < nodes - 10)
	{
		if (head->next == NULL)
			return (0);
		head = head->next;
		i++;
	}
	i = 0;
	max = 0;
	while(i < 10)
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
	while(i < 50)
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
	while (i < nodes - 50) // range;
	{
		if (head->next == NULL)
			return (0);
		head = head->next;
		i++;
	}
	i = 0;
	max = 0;
	while(i < 50) // range;
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

void	show_stack(t_node *head_a, t_node *head_b)
{
	printf("Stack a:\n");
	while (head_a != NULL)
	{
		printf("%d\n", head_a->value);
		head_a = head_a->next;
	}
	printf("Stack b:\n");
	while (head_b != NULL)
	{
		printf("%d\n", head_b->value);
		head_b = head_b->next;
	}
}

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

int	calc_steps(t_node *head, int max)
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
		return (0); // reverse_rotate instead of rotate then;
	return (1);
}

void	sort_b_backwards(t_node **head_a, t_node **head_b)
{
	int	max;

	while (count_nodes(*head_b) > 0)
	{
		max = find_max(*head_b);
		if (calc_steps(*head_b, max))
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
		push_a(head_a, head_b);
	}
}

void	push_first_element(t_node **head_a, t_node **head_b, int max)
{
	if (calc_steps(*head_a, max))
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
}

int	get_max(t_node *head_a)
{
	int	max_top;
	int	max_bot;

	max_top = find_max_top(head_a, (count_nodes(head_a) / 5));
	max_bot = find_max_bot(head_a, (count_nodes(head_a) / 5));
	if (max_top > max_bot)
		return (max_top);
	else
		return (max_bot);
}

int	get_bigger_element(t_node **head_a, t_node **head_b, int argc)
{
	int	cmd_count;

	cmd_count = new_check_a(*head_a, *head_b);
	if (cmd_count >= 1 && cmd_count < 50 && count_nodes(*head_a) > 100)
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

void	get_next_element(t_node **head_a, t_node **head_b)
{
	int	max_top;
	int	max_bot;

	if (count_nodes(*head_a) > 10)
	{
		max_top = scan_top(*head_a);
		max_bot = scan_bot(*head_a);
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

int main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		max;

	init_stack(argc, argv, &head_a);
	max = get_max(head_a);
	push_first_element(&head_a, &head_b, max);
	while (count_nodes(head_a) > 0)
	{
		if (get_bigger_element(&head_a, &head_b, argc))
			element_found(&head_a, &head_b);
		else
		{
			get_next_element(&head_a, &head_b);
			element_found(&head_a, &head_b);
		}
	}
	sort_b_backwards(&head_a, &head_b);
	return (0);
}
