/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:43:46 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/10 20:15:04 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_ft(int *********nbr);
void	ft_putchar(char c);

int	main(void)
{
	int	nbr;
	int*	a;
	int**	b;
	int***	c;
	int****	d;
	int*****	e;
	int******	f;
	int*******	g;
	int********	h;

	nbr = 1;
	a = &nbr;
	b = &a;
	c = &b;
	d = &c;
	e = &d;
	f = &e;
	g = &f;
	h = &g;

	ft_ultimate_ft(&h);
	ft_putchar(********h + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 5;
}
