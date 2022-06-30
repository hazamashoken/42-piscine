/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:24:13 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/12 15:30:54 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
/*
@breif			print out top 'o----o' and bottom part of the box
@param	int	w	width of the box
@return	void
*/

void	ft_topbot(int w)
{
	int	i;

	i = 1;
	while (i <= w)
	{
		if (i == 1 || i == w)
			ft_putchar('o');
		else
			ft_putchar('-');
		i++;
	}
}

/*
@brief			print wall '|'  and blank ' ' for the box body
@param	int	w	width of the box
@return void
*/
void	ft_wall(int w)
{
	int	i;

	i = 1;
	while (i <= w)
	{
		if (i == 1 || i == w)
			ft_putchar('|');
		else
			ft_putchar(' ');
		i++;
	}
}

/*
@breif			call ft_topbot or ft_wall depend on the height if height is 0 or max
@param	int	w	width of the box
@param	int	h	height of the box
@return	void
*/
void	rush(int x, int y)
{
	int	hi;	

	if (x < 1 || y < 0 || x > 2147483647 || y > 2147483647)
	{
		write(1, "Value out of range.", 19);
		return ;
	}
	hi = 1;
	while (hi <= y)
	{
		if (hi == 1 || hi == y)
			ft_topbot(x);
		else
			ft_wall(x);
		ft_putchar('\n');
		hi++;
	}
}
