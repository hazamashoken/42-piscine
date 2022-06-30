/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:04:22 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/10 21:41:50 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_putchar(char c);

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 9;
	b = 2;
	ft_div_mod(a, b, &div, &mod);
	ft_putchar(div + '0');
	ft_putchar(mod + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
