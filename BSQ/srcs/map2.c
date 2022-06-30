/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:35:44 by abossel           #+#    #+#             */
/*   Updated: 2022/06/28 09:27:43 by abossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"

void	clear_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->empty = '\0';
	map->obstacle = '\0';
	map->full = '\0';
	map->data = NULL;
}

int	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->data[i] == NULL)
			break ;
		free(map->data[i]);
		i++;
	}
	free(map->data);
	clear_map(map);
	return (0);
}
