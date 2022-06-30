/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:35:44 by abossel           #+#    #+#             */
/*   Updated: 2022/06/28 15:48:47 by abossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_libft.h"
#include "freezero.h"
#include "solution.h"
#include "map.h"

/*
@brief	the main function use to read and compute the map
@params	int	file	the file to compute
@return non
*/
void	bsq(int file)
{
	t_map	map;

	if (file != -1)
	{
		if (read_map_info(file, &map))
		{
			if (read_map_data(file, &map))
			{
				solve(&map);
				print_map(&map);
			}
			else
				ft_puterr("map error\n");
		}
		else
			ft_puterr("map error\n");
		return ;
	}
	ft_puterr("map error\n");
}

/*
edit note 1: allow it to accept multiple map -280622
edit note 2: allow it to read from stdin (see ft_file) -280622
edit note 3: move the main part into another function for easier access
*/
int	main(int argc, char **argv)
{
	int		file;
	int		i;

	i = 1;
	if (argc == 1)
	{
		bsq(0);
	}
	while (i < argc)
	{
		file = open(argv[i++], O_RDONLY);
		bsq(file);
	}
	return (0);
}
