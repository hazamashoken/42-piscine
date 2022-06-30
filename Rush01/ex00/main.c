/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:08:13 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 12:25:33 by wkasetta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_error_message(void)
{
	ft_putstr("...Error...\n");
}

int	main(int argc, char *argv[])
{
	int		size;
	char	**tab;

	if (argc != 2)
	{
		ft_error_message();
		return (0);
	}
	size = ft_get_size(argv[1]);
	tab = ft_init_tab(argv[1], size);
	if (size == 0)
	{
		ft_error_message();
	}
	else if (tab != 0)
	{
		if (ft_solve(tab, size))
			ft_print_tab(tab, size);
		else
			ft_putstr("no solution found\n");
		ft_destroy_tab(tab, size);
	}
	else
		ft_error_message();
	return (0);
}
