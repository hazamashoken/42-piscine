/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:23:47 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 02:49:14 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
@brief	helper function for delta height

*/

void	ft_check_delta(int delta, int size, int *max, int *n)
{
	if (delta > 0)
	{
		*max = size;
		*n = 0;
	}
	else
	{
		*max = -1;
		*n = size -1;
	}
}

/*
@brief		check if the current pos height is corrrectly place
@params		char**	tab		table/board
@params		int		x		x coor
@params		int		delta	the change in valu to be made
@params		int		size	size of table N x N
*/

int	ft_height_col(char **tab, int x, int delta, int size)
{
	int	y;
	int	max;
	int	vmax;
	int	height;

	ft_check_delta(delta, size, &max, &y);
	vmax = 0;
	height = 0;
	while (y != max)
	{
		if (!tab[y][x])
			return (0);
		if (tab[y][x] > vmax)
		{
			vmax = tab[y][x];
			height++;
		}
		y += delta;
	}
	return (height);
}

/*
@brief		check if the current pos height is corrrectly place
@params		char**	tab		table/board
@params		int		y		y coor
@params		int		delta	the change in valu to be made
@params		int		size	size of table N x N
*/
int	ft_height_row(char **tab, int y, int delta, int size)
{
	int	x;
	int	max;
	int	vmax;
	int	height;

	ft_check_delta(delta, size, &max, &x);
	vmax = 0;
	height = 0;
	while (x != max)
	{
		if (tab[y][x] > vmax)
		{
			vmax = tab[y][x];
			height++;
		}
		x += delta;
	}
	return (height);
}

/*
@brief	check if there's duplicate value in the col and row
@params	char**	tab		table/board
@params	int		x		x coor
@params	int		y		y coor
@params	int		size	size of the board
*/
int	ft_is_duplicate(char **tab, int x, int y, int size)
{
	int	i;

	if (!tab[y][x])
		return (0);
	i = y;
	while (i--)
		if (tab[y][x] == tab[i][x])
			return (1);
	i = y;
	while (++i < size)
		if (tab[y][x] == tab[i][x])
			return (1);
	i = x;
	while (i--)
		if (tab[y][x] == tab[y][i])
			return (1);
	i = x;
	while (++i < size)
		if (tab[y][x] == tab[y][i])
			return (1);
	return (0);
}
