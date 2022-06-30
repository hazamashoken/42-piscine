/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:49:08 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 14:54:51 by tpomsati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

/*
@brief	check value against the rules/input 
@brief	return 1 if it follow rule else return 0
@params	char**	tab	table
@params	int	x	x coor of table
@params	int	y	y coor of table
@params	int	size	size of the table
@return	int			1 if valid else 0
*/

int	ft_is_valid_value(char **tab, int x, int y, int size)
{
	if (ft_is_duplicate(tab, x, y, size)
		|| ft_height_col(tab, x, 1, size) > tab[x][size] || (y == size - 1
		&& ft_height_col(tab, x, -1, size) != tab[x][size + 1])
		|| ft_height_row(tab, y, 1, size) > tab[y][size + 2] || (x == size - 1
		&& ft_height_row(tab, y, -1, size) != tab[y][size + 3]))
		return (0);
	return (1);
}

/*
@brief	recursively check if input is valid 
@params	char** tab	table/board
@params	int	n	
@params	int	size	size of the board N x N
@return	int			1 or 0 depend of if it reach the end successfully
*/
int	ft_backtrack(char **tab, int n, int size)
{
	int	i;
	int	x;
	int	y;

	if (n == size * size)
		return (1);
	i = 0;
	x = n % size;
	y = n / size;
	while (++i <= size)
	{
		tab[y][x] = i;
		if (ft_is_valid_value(tab, x, y, size))
		{
			if (ft_backtrack(tab, n + 1, size))
				return (1);
			tab[y][x] = 0;
		}
	}
	tab[y][x] = 0;
	return (0);
}

/*
@brief	check if value in table is over size else move on to recursive solving
@params	char**	tab		table/board
@params	int		size	size of the board N x N
@return int				1 or 0 depend if it can solve the board with given input
*/

int	ft_solve(char **tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tab[i][size] + tab[i][size + 1] > size + 1
			|| tab[i][size + 2] + tab[i][size + 3] > size + 1)
			return (0);
	}
	return (ft_backtrack(tab, 0, size));
}
