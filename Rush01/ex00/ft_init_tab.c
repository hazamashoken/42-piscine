/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:49:56 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 15:37:11 by tpomsati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
@brief	malloc the 2D table and initate the table with 0;
@brief create tab size + 4 (4*8) and put rules -> 5-8 
*/

char	**ft_init_tab(char *str, int size)
{
	char	**tab;
	int		x;
	int		y;

	tab = malloc(size * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	y = -1;
	while (++y < size)
	{
		tab[y] = malloc((size + 4) * sizeof(char));
		if (tab[y] == NULL)
			return (NULL);
		x = -1;
		while (++x < size)
			tab[y][x] = 0;
		x = -1;
		while (++x < 4)
			tab[y][size + x] = str[2 * (y + x * size)] - '0';
	}
	return (tab);
}
