/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:22:39 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 01:19:56 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

/*
@brief	take in 2D array size and print out in N x N layout
@params	char**	tab		2D array of box layout
@params	int		size	size of 2D array
*/
void	ft_print_tab(char **tab, int size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(tab[y][x] + '0');
			if (++x < size)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		y++;
	}
}
