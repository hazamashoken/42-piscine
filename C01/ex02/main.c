/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:19:39 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/10 20:34:41 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b);
void	ft_putchar(char c);

int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	ft_swap(&a, &b);
	ft_putchar(a + 48);
	ft_putchar(b + 48);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
