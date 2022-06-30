/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:20:45 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/11 07:40:49 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	tab[5] = {5, 4, 3, 2, 1};
	int	i;
	int	size;

	i = 0;
	size = 5;
	ft_rev_int_tab(tab, size);
	while (i < size)
		ft_putchar(tab[i++] + '0');
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i++] = tab[j];
		tab[j--] = temp;
	}
}
