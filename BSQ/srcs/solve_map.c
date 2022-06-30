/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:30:17 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/28 13:56:49 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "solution.h"
#include "map.h"

void	solve_map(t_map *map, t_sol sol)
{
	int	x;
	int	y;
	int	x_start;
	int	y_start;

	x_start = sol.x;
	y_start = sol.y;
	y = sol.y;
	while (y < y_start + sol.size)
	{
		x = sol.x;
		while (x < x_start + sol.size)
		{
			map->data[y][x] = map->full;
			x++;
		}
		y++;
	}
}
