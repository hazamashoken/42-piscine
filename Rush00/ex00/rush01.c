/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:02:52 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/12 14:39:12 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

/*
@breif			print out top 'ABBBBA' and bottom 'CBBBBC' part of the box
@param	int	w	width of the box
@param	int	h	height of the box
@param	int	hi	current height when outputing box
@return	void
*/
void	ft_topbot(int w, int h, int hi)
{
	int	i;

	i = 1;
	while (i <= w)
	{
		if ((i == 1 && hi == 1) || (i == w && hi == h))
			ft_putchar('/');
		else if ((i == 1 && hi == h) || (i == w && hi == 1))
			ft_putchar('\\');
		else
			ft_putchar('*');
		i++;
	}
}

/*
@brief			print wall 'B'  and blank ' ' for the box body
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
			ft_putchar('*');
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

	hi = 1;
	while (hi <= y)
	{
		if (hi == 1 | hi == y)
			ft_topbot(x, y, hi);
		else
			ft_wall(x);
		if (hi != y)
			ft_putchar('\n');
		hi++;
	}
	ft_putchar('\n');
}
