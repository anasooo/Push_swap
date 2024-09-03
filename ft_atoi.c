/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asodor <asodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:31:12 by asodor            #+#    #+#             */
/*   Updated: 2024/08/25 15:47:32 by asodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *s, t_stack_node **a)
{
	int		i;
	int		sign;
	long	res;
	int		len;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	sign = 1;
	len = 0;
    if ((s[i] == '-' || s[i] == '+')){
        if (s[i] == '-')
            sign *= -1;
        i++;
        len++;
    }
	res = 0;
	while (s[i] && s[i] == '0')
		i++;
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + (s[i] - '0');
		i++;
		len++;
	}
	res *= sign;
	if (res > 2147483647 || res < -2147483648 || len > 11)
		ft_error(a);
	return (res);
}