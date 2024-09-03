/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 09:39:52 by asodor            #+#    #+#             */
/*   Updated: 2024/08/25 17:42:05 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack_node **a)
{
	if (stack_len(*a) != 0)
		ft_clear_lst(a);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_string(char *s)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i]) || s[i] == ' ' || s[i] == '-' || s[i] == '+'))
			return (0);
		if (ft_isdigit(s[i]))
			d = 1;
		i++;
	}
	return (d);
}

int	ft_valid(char *s)
{
	int	i;

	i = 0;
	if (check_string(s) == 0)
		return (0);
	while (s[i] && ft_isspace(s[i]))
		i++;
	if ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (1);
	if (ft_isdigit(s[i]))
		return (2);
	if ((s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
		return (2);
	return (0);
}

void	check_dup(t_stack_node **a)
{
	t_stack_node	*curr;
	t_stack_node	*next;

	curr = (*a);
	next = (*a)->next;
	while (curr->next)
	{
		while (next)
		{
			if (curr->value == next->value)
				ft_error(a);
			next = next->next;
		}
		curr = curr->next;
		next = curr->next;
	}
}

void	stack_init(int ac, char **av, t_stack_node **a)
{
	int	i;
	int	check;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			check = ft_valid(av[i]);
			if (check == 2)
				ft_split(av[i], a);
			else if (check == 1)
				append_node(a, ft_atoi(av[i], a));
			else
				ft_error(a);
			i++;
		}
	}
	else
		exit(0);
	check_dup(a);
}
