/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpomsati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:00:41 by tpomsati          #+#    #+#             */
/*   Updated: 2022/06/12 15:25:13 by tpomsati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_topbot(int w)
{
	int	i;

	i = 1;
	while (i <= w)
	{
		if (i == 1)
		{
			ft_putchar('A');
		}
		else if (i == w)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		i ++;
	}
}

void	ft_wall(int w)
{	
	int	i;

	i = 1;
	while (i <= w)
	{
		if (i == 1 || i == w)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		i ++;
	}
}

void	rush(int w, int h)
{
	int	hi;

	hi = 1;
	while (hi <= h)
	{
		if (hi == 1 || hi == h)
		{
			ft_topbot(w);
		}
		else
		{
			ft_wall(w);
		}		
		ft_putchar('\n');
		hi ++;
	}	
}
