/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:35:23 by abossel           #+#    #+#             */
/*   Updated: 2022/06/28 13:55:08 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_H
# define SOLUTION_H

# include "map.h"

typedef struct s_sol
{
	int	x;
	int	y;
	int	size;
}	t_sol;

void	solve(t_map *map);
void	solve_map(t_map *map, t_sol sol);

#endif
