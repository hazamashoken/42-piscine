/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:02:11 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/10 10:24:47 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ft(int *nbr);
void	ft_putchar(char c);

int	main(void)
{
	int	n;

	n = 5;
	ft_putchar(*&n + 48);
	ft_ft(&n);
	ft_putchar(*&n / 10 + 48);
	ft_putchar(*&n % 10 + 48);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
