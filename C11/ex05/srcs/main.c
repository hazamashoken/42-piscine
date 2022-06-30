/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:47:08 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/25 13:27:33 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_do_op.h"

int	operator(int n1, char *c, int n2)
{
	int	(*operator[5])(int, int);

	operator[0] = &ft_add;
	operator[1] = &ft_sub;
	operator[2] = &ft_mul;
	operator[3] = &ft_div;
	operator[4] = &ft_mod;
	if (c[0] == '+')
		return (operator[0](n1, n2));
	else if (c[0] == '-')
		return (operator[1](n1, n2));
	else if (c[0] == '*')
		return (operator[2](n1, n2));
	else if (c[0] == '/')
		return (operator[3](n1, n2));
	else if (c[0] == '%')
		return (operator[4](n1, n2));
	else
		return (0);
}

void	do_op(char *s1, char *op, char *s2)
{
	int	n1;
	int	n2;
	int	res;

	res = 1;
	n1 = ft_atoi(s1);
	n2 = ft_atoi(s2);
	if (!(op[0] == '-' || op[0] == '+' || op[0] == '/'
			|| op[0] == '*' || op[0] == '%'))
		write(1, "0", 1);
	else if (op[0] == '/' && n2 == 0)
		write(1, "Stop : division by zero\n", 23);
	else if (op[0] == '%' && n2 == 0)
		write(1, "Stop : modulo by zero\n", 21);
	else
	{
		res = operator(n1, op, n2);
		ft_putnbr(res);
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
		do_op(argv[1], argv[2], argv[3]);
	return (0);
}
