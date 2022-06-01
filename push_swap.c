/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:58:42 by fyuzhyk           #+#    #+#             */
/*   Updated: 2022/05/28 09:58:10 by fyuzhyk          ###   ########.fr       */
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
		if((head_a->value) < (head_a->next->value))
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

int	order_b(t_node *head_b) //checks if a is already in the correct order;
{
	int	control;
	int	count;

	control = 0;
	count = 0;
	if (head_b == NULL)
		return (control);
	// while (head_b->next != NULL)
	// {
	// 	if((head_b->value) > (head_b->next->value))
	// 	{
	// 		head_b = head_b->next;
	// 		count++;
	// 	}
	// 	else
	// 		return (control);
	// }
	// control = 1;
	// return (control);
	while (head_b->next != NULL)
	{
		if((head_b->value) > (head_b->next->value))
			count++;
		else
			break ;
		head_b = head_b->next;
	}
	if (count >= 3)
		return (1);
	return (0);
}

int	new_order_a(t_node *head_a)
{
	int	control;
	int	count;

	control = 0;
	count = 0;
	if (head_a == NULL)
		return (control);
	while (head_a->next != NULL)
	{
		if((head_a->value) < (head_a->next->value)) // the right order for a;
			count++;
		else
			break ;
		head_a = head_a->next;
	}
	if (count >= 3)
		return (1);
	return (0);
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

int	find_min(t_node *head)
{
	int	min;

	min = head->value;
	while(head != 0)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
	return (min);
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

int	check_second_last_max(t_node *head, int argc, int max)
{
	int	i;
	int	count;

	i = 0;
	count = count_nodes(head);
	while(i < (count - 2))
	{
		head = head->next;
		i++;
	}
	if (head->value == max)
		return (1);
	return (0);
}

int	check_second_last_min(t_node *head, int argc, int min)
{
	int	i;

	i = 0;
	while(i < (argc - 3))
	{
		if (head == NULL)
			return (0) ;
		head = head->next;
		i++;
	}
	if (head == NULL)
		return (0);
	if (head->value == min)
		return (1);
	return (0);
}

int	check_min_last(t_node *head, int min)
{
	if (lstlast(head)->value == min)
		return (1);
	return (0);
}

void	check_position_max_a(t_node **head_a, int max, int argc)
{
	if ((*head_a) == NULL)
		return ;
	if ((*head_a)->value == max) // if top of stack is max;
	{
		rotate(head_a);
		ft_putstr_fd("ra\n", 1);
		return ;
	}
	if((*head_a)->next->value == max) // if second_top is max;
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
		rotate(head_a);
		ft_putstr_fd("ra\n", 1);
		return ;
	}
	if (check_second_last_max((*head_a), argc, max)) // if second_last is max;
	{
		reverse_rotate(head_a);
		ft_putstr_fd("rra\n", 1);
		return ;
	}
}

void	check_position_max_b(t_node **head_b, int max, int argc)
{
	if ((*head_b) == NULL)
		return ;
	if (lstlast((*head_b))->value == max)
	{
		reverse_rotate(head_b);
		ft_putstr_fd("rrb\n", 1);
		return ;
	}
}

void	check_position_min_b(t_node **head_b, int min, int argc)
{
	if ((*head_b) == NULL)
		return ;
	if ((*head_b)->value == min)
	{
		if ((*head_b)->next == NULL)
			return ;
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
		return ;
	}
	if ((*head_b)->next == NULL)
		return ;
	if ((*head_b)->next->value == min)
	{
		if (count_nodes((*head_b)) == 2)
			return ;
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
		return ;
	}
	if (check_second_last_min((*head_b), argc, min))
	{
		reverse_rotate(head_b);
		ft_putstr_fd("rrb\n", 1);
		return ;
	}
}

void	check_position_min_a(t_node **head_a, t_node **head_b, int min, int argc)
{
	if ((*head_a) == NULL)
		return ;
	if ((*head_a)->value == min)
	{
		push_b(head_a, head_b);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	if ((*head_a)->next->value == min)
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
		push_b(head_a, head_b);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	if (lstlast((*head_a))->value == min)
	{
		reverse_rotate(head_a);
		ft_putstr_fd("rra\n", 1);
		push_b(head_a, head_b);
		ft_putstr_fd("pb\n", 1);
	}
}

void	check_a(t_node **head_a, t_node **head_b)
{
	if ((*head_a) == NULL)
		return ;
	if ((*head_a)->next == NULL)
	{
		push_b(head_a, head_b);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	if ((*head_a)->value > (*head_a)->next->value)
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (lstlast((*head_a))->value < (*head_a)->value)
	{
		reverse_rotate(head_a);
		ft_putstr_fd("rra\n", 1);
	}
	// if (!order_a((*head_a)))
	// {
	// 	push_b(head_a, head_b);
	// 	ft_putstr_fd("pb\n", 1);
	// }
	push_b(head_a, head_b);
	ft_putstr_fd("pb\n", 1);
}

void	check_b(t_node **head_b)
{
	if ((*head_b) == NULL)
		return ;
	if ((*head_b)->next == NULL)
		return ;
	if (find_min((*head_b)) == (*head_b)->value)
	{
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
	}
	if (find_min((*head_b)) == (*head_b)->next->value && (*head_b)->next->next != NULL)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
	}
	if ((*head_b)->value < (*head_b)->next->value)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
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
	if ((*head_b)->next == NULL)
	{
		push_a(head_a, head_b);
		ft_putstr_fd("pa\n", 1);
		return ;
	}
	if ((*head_b)->value < (*head_b)->next->value)
	{
		swap(head_b);
		ft_putstr_fd("sb\n", 1);
	}
	push_a(head_a, head_b);
	ft_putstr_fd("pa\n", 1);
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

void	check_a_reverse(t_node **head_a)
{
	if ((*head_a) == NULL)
		return ;
	if ((*head_a)->next == NULL)
		return ;
	if ((*head_a)->value > (*head_a)->next->value)
	{
		swap(head_a);
		ft_putstr_fd("sa\n", 1);
	}
}

void	sort_rotate_b(t_node **head_a, t_node **head_b, int max, int min, int argc)
{
	int	i;

	i = 1;
	while (i < count_nodes((*head_b)))
	{
		if ((*head_b)->value < (*head_b)->next->value)
		{
			swap(head_b);
			ft_putstr_fd("sb\n", 1);
		}
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
		i++;
	}
	if (find_min((*head_b)) == (*head_b)->value)
	{
		rotate(head_b);
		ft_putstr_fd("rb\n", 1);
	}
}

void	sort_rotate_a(t_node **head_a, t_node **head_b, int max, int min, int argc)
{
	int	i;

	i = 1;
	while (i < count_nodes((*head_a)))
	{
		if ((*head_a)->value > (*head_a)->next->value)
		{
			swap(head_a);
			ft_putstr_fd("sa\n", 1);
		}
		rotate(head_a);
		ft_putstr_fd("ra\n", 1);
		i++;
	}
	if (find_max((*head_a)) == (*head_a)->value)
	{
		rotate(head_a);
		ft_putstr_fd("ra\n", 1);
	}
}

int main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	int		max;
	int		min;

	init_stack(argc, argv, &head_a);
	min = find_min(head_a);
	max = find_max(head_a);
	int i = 25;
	int j = 0;
	int control = 0;
	while (1)
	{
		while (1)
		{
			check_a(&head_a, &head_b);
			if (count_nodes(head_a) == i)
				break ;
			check_b(&head_b);
			if (count_nodes(head_a) == i)
				break ;
		}
		if (order_b(head_b))
		{
			i = i - 5;
			j = j + 5;
		}
		if (i == -5) // marks end of the first part;
		{
			i = 0;
			j = 25;
			while (1)
			{
				while (1)
				{
					check_a_reverse(&head_a);
					if (count_nodes(head_b) == j)
						break ;
					check_b_reverse(&head_a, &head_b);
					if (count_nodes(head_b) == j)
						break ;
				}
				if (new_order_a(head_a))
				{
					i = i + 5;
					j = j - 5;
				}
				while (1)
				{
					check_a(&head_a, &head_b);
					if (count_nodes(head_a) == i)
						break ;
					check_b(&head_b);
					if (count_nodes(head_a) == i)
						break ;
				}
			}
		}
		while (1)
		{
			check_a_reverse(&head_a);
			if (count_nodes(head_b) == j)
				break ;
			check_b_reverse(&head_a, &head_b);
			if (count_nodes(head_b) == j)
				break ;
		}
		if (order_a(head_a) && count_nodes(head_b) == 0)
			break ;
		// sort_rotate_b(&head_a, &head_b, max, min, argc);
		// // sort_rotate_a(&head_a, &head_b, max, min, argc);
		// i = 20;
		// while (1)
		// {
		// 	check_position_max_a(&head_a, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_a(&head_a, &head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_max_b(&head_b, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_b(&head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_a(&head_a, &head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_b(&head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// }
		// // sort_rotate_b(&head_a, &head_b, max, min, argc);
		// i = 15;
		// while (1)
		// {
		// 	check_position_max_a(&head_a, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_a(&head_a, &head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_max_b(&head_b, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_b(&head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_a(&head_a, &head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_b(&head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// }
		// // sort_rotate_b(&head_a, &head_b, max, min, argc);
		// i = 10;
		// while (1)
		// {
		// 	check_position_max_a(&head_a, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_a(&head_a, &head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_max_b(&head_b, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_b(&head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_a(&head_a, &head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_b(&head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// }
		// // sort_rotate_b(&head_a, &head_b, max, min, argc);
		// i = 5;
		// while (1)
		// {
		// 	check_position_max_a(&head_a, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_a(&head_a, &head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_max_b(&head_b, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_b(&head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_a(&head_a, &head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_b(&head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// }
		// i = 2;
		// while (1)
		// {
		// 	check_position_max_a(&head_a, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_a(&head_a, &head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_max_b(&head_b, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_b(&head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_a(&head_a, &head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_b(&head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// }
		// sort_rotate_b(&head_a, &head_b, max, min, argc);
		// i = 25;
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// }
		// // sort_rotate_a(&head_a, &head_b, max, min, argc);
		// i = 20;
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// }
		// // sort_rotate_a(&head_a, &head_b, max, min, argc);
		// i = 15;
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// }
		// // sort_rotate_a(&head_a, &head_b, max, min, argc);
		// i = 10;
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// }
		// // sort_rotate_a(&head_a, &head_b, max, min, argc);
		// i = 5;
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// }
		// // sort_rotate_a(&head_a, &head_b, max, min, argc);
		// i = 0;
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// }
		// // sort_rotate_b(&head_a, &head_b, max, min, argc);
		// sort_rotate_a(&head_a, &head_b, max, min, argc);
		// i = 2;
		// while (1)
		// {
		// 	check_position_max_a(&head_a, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_a(&head_a, &head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_max_b(&head_b, max, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_position_min_b(&head_b, min, argc);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_a(&head_a, &head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// 	check_b(&head_b);
		// 	if (count_nodes(head_a) == i)
		// 		break ;
		// }
		// i = 0;
		// // sort_rotate_b(&head_a, &head_b, max, min, argc);
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == i)
		// 		break ;
		// }
		// sort_rotate_a(&head_a, &head_b, max, min, argc);
		// sort_rotate_a(&head_a, &head_b, max, min, argc);
		// if (count_nodes(head_b) == 0 && order_a(head_a))
		// 	break ;
		// while (1)
		// {
		// 	check_position_max_a(&head_a, max, argc);
		// 	if (count_nodes(head_a) == 15)
		// 		break ;
		// 	check_position_min_a(&head_a, &head_b, min, argc);
		// 	if (count_nodes(head_a) == 15)
		// 		break ;
		// 	check_position_max_b(&head_b, max, argc);
		// 	if (count_nodes(head_a) == 15)
		// 		break ;
		// 	check_position_min_b(&head_b, min, argc);
		// 	if (count_nodes(head_a) == 15)
		// 		break ;
		// 	check_a(&head_a, &head_b);
		// 	if (count_nodes(head_a) == 15)
		// 		break ;
		// 	check_b(&head_b);
		// 	if (count_nodes(head_a) == 15)
		// 		break ;
		// }
		// sort_rotate_a(&head_a, &head_b, max, min, argc);
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == 0)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == 0)
		// 		break ;
		// }
		// sort_rotate_b(&head_a, &head_a, max, min, argc);
		// while (1)
		// {
		// 	check_position_max_a(&head_a, max, argc);
		// 	if (count_nodes(head_a) == 10)
		// 		break ;
		// 	check_position_min_a(&head_a, &head_b, min, argc);
		// 	if (count_nodes(head_a) == 10)
		// 		break ;
		// 	check_position_max_b(&head_b, max, argc);
		// 	if (count_nodes(head_a) == 10)
		// 		break ;
		// 	check_position_min_b(&head_b, min, argc);
		// 	if (count_nodes(head_a) == 10)
		// 		break ;
		// 	check_a(&head_a, &head_b);
		// 	if (count_nodes(head_a) == 10)
		// 		break ;
		// 	check_b(&head_b);
		// 	if (count_nodes(head_a) == 10)
		// 		break ;
		// }
		// // sort_rotate_b(&head_a, &head_a, max, min, argc);
		// while (1)
		// {
		// 	check_position_max_a(&head_a, max, argc);
		// 	if (order_a(head_a))
		// 		break ;
		// 	check_position_min_a(&head_a, &head_b, min, argc);
		// 	if (order_a(head_a))
		// 		break ;
		// 	check_position_max_b(&head_b, max, argc);
		// 	if (order_a(head_a))
		// 		break ;
		// 	check_position_min_b(&head_b, min, argc);
		// 	if (order_a(head_a))
		// 		break ;
		// 	check_a(&head_a, &head_b);
		// 	if (order_a(head_a))
		// 		break ;
		// 	check_b(&head_b);
		// 	if (order_a(head_a))
		// 		break ;
		// }
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == 15)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == 15)
		// 		break ;
		// }
		// sort_rotate_a(&head_a, &head_a, max, min, argc);
		// sort_rotate_a(&head_a, &head_a, max, min, argc);
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == 10)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == 10)
		// 		break ;
		// }
		// sort_rotate_a(&head_a, &head_a, max, min, argc);
		// sort_rotate_a(&head_a, &head_a, max, min, argc);
		// break ;
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (count_nodes(head_b) == 0)
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (count_nodes(head_b) == 0)
		// 		break ;
		// }
		// if (order_a(head_a))
		// if (!order_b(head_b))
		// 	sort_rotate_b(&head_a, &head_b, max, min, argc);
		// while (1)
		// {
		// 	check_a_reverse(&head_a);
		// 	if (!order_a(head_a) || order_b(head_b))
		// 		break ;
		// 	check_b_reverse(&head_a, &head_b);
		// 	if (!order_a(head_a) || order_b(head_b))
		// 		break ;
		// }
		// if (!order_a(head_a))
		// 	sort_rotate_b(&head_a, &head_b, max, min, argc);
		// if (count_nodes(head_b) == 0 || order_a(head_a))
		// if (count_nodes(head_b) == 0 && order_a(head_a))
		// 	break ;
	}
	// if (order_a(head_a) && order_b(head_b))
	// {
	// 	while(head_b)
	// 	{
	// 		push_a(&head_a, &head_b);
	// 		ft_putstr_fd("pa\n", 1);
	// 	}
	// }
	// printf("--------\n");
	// show_stack(head_a, head_b);
	// printf("--------\n");
	// printf("start of second the second part:\n");
	// while (1)
	// {
	// 	check_a_reverse(&head_a);
	// 	if (count_nodes(head_b) == 0)
	// 		break ;
	// 	check_b_reverse(&head_a, &head_b);
	// 	if (count_nodes(head_b) == 0)
	// 		break ;
	// }
	// printf("\n");
	// show_stack(head_a, head_b);
	// printf("Here comes stack a\n");
	// while (head_a != NULL)
	// {
	// 	printf("%d\n", head_a->value);
	// 	head_a = head_a->next;
	// }
	// printf("Here comes stack b\n");
	// while (head_b != NULL)
	// {
	// 	printf("%d\n", head_b->value);
	// 	head_b = head_b->next;
	// }
	return (0);
}


/*
spilt the stack;
swap a part along until it is sorted;
if it is sorted, let it wait in b;
then sort the others using the same technique (?)
*/
