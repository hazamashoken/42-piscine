/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:11:36 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 10:12:07 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_error(char *prog, char *file)
{
	ft_putstrf(basename(prog), 2);
	ft_putstrf(": ", 2);
	ft_putstrf(file, 2);
	ft_putstrf(": ", 2);
	ft_putstrf(strerror(errno), 2);
	ft_putstrf("\n", 2);
}

int	main(int argc, char **argv)
{
	int	file;
	int	i;

	if (argc == 1)
	{
		ft_print_file(0);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		file = 0;
		if (ft_strcmp(argv[i], "-") != 0)
			file = open(argv[i], O_RDONLY);
		if (file != -1)
		{
			ft_print_file(file);
			close(file);
		}
		else
			ft_print_error(argv[0], argv[i]);
		i++;
	}
	return (0);
}
