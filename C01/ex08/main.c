/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 07:42:29 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/11 07:52:42 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	tab[5] = {2,7,4,9,1};
	int	i;
	int	size;

	size = 5;
	i = 0;
	while (i < size)
		ft_putchar(tab[i++] + '0');
	write(1, " ", 1);
	ft_sort_int_tab(tab, size);
	i = 0;
	while (i < size)
		ft_putchar(tab[i++] + '0');
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
