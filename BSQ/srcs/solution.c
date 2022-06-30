/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:36:57 by abossel           #+#    #+#             */
/*   Updated: 2022/06/28 14:00:43 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include "map.h"
#include "ft_libft.h"

int	find_box(t_map *map, int x, int y)
{
	int	size;
	int	i;

	size = 1;
	while (y + size < map->height && x + size < map->width)
	{
		i = 0;
		while (i <= size)
		{
			if (x + i >= map->width
				|| map->data[y + size][x + i] == map->obstacle)
				return (size);
			if (y + i >= map->height
				|| map->data[y + i][x + size] == map->obstacle)
				return (size);
			i++;
		}
		size++;
	}
	return (size);
}

void	set_sol(t_sol *sol, int x, int y, int size)
{
	sol->x = x;
	sol->y = y;
	sol->size = size;
}

void	solve(t_map *map)
{
	int		x;
	int		y;
	int		size;
	t_sol	sol;

	sol.size = ((size = ((y = 0))));
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((map->data)[y][x] != map->obstacle)
			{
				size = find_box(map, x, y);
				if (size > sol.size)
					set_sol(&sol, x, y, size);
			}
			x++;
		}
		y++;
	}
	solve_map(map, sol);
}
