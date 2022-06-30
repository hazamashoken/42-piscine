/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:49:22 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/26 13:13:11 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void	print_nb(int nb, t_dict *begin_list)
{
	while (begin_list->suf == 1 || nb != begin_list->nb)
		begin_list = begin_list->next;
	ft_putstr(begin_list->literal);
	if (nb < 20 || nb > 99)
	{
		ft_putchar(' ');
	}
}

void	print_suff(int i, char *nbr, int j, t_dict *begin_list)
{
	while (begin_list->suf == 0 || j != begin_list->nb)
		begin_list = begin_list->next;
	ft_putstr(begin_list->literal);
	while (nbr[i] == '0')
		i++;
	if (nbr[i] != '\0' && i != (check_length(nbr) - 1)
		&& i != check_length(nbr) - 2)
		ft_putstr(", ");
	if (i == (check_length(nbr) - 1) || i == (check_length(nbr) - 2))
		ft_putchar(' ');
}

void	print_units(int nbr, char *nbrc, int i, t_dict *begin_list)
{
	int		nb;

	if ((nbr % 100) >= 20)
	{
		check_and(nbr, i, nbrc);
		print_nb((nb = (nbr % 100) - (nbr % 10)), begin_list);
		if (nbr % 10 != 0)
		{
			nb = nbr % 10;
			ft_putstr("-");
			print_nb(nb, begin_list);
		}
	}
	else if ((nbr % 100) < 20 && (nbr % 100 != 0))
	{
		print_nb((nb = nbr % 100), begin_list);
	}
}

void	print_hundreds(int nbr, char *nbrc, int i, t_dict *begin_list)
{
	int		nb;

	if ((nbr / 100) > 0)
	{
		nb = nbr / 100;
		print_nb(nb, begin_list);
		print_nb(100, begin_list);
	}
	if (check_nb(nbr % 100, begin_list) == 1)
	{
		check_and(nbr, i, nbrc);
		print_nb(nbr % 100, begin_list);
		if ((nbr % 100) >= 20)
			ft_putstr(" ");
	}
	else
	{
		print_units(nbr, nbrc, i, begin_list);
	}
}

void	send_to_print(int nbr, t_dict *begin_list, int i, char *nbrc)
{
	int		nb;

	nb = nbr;
	if (check_nb(nb, begin_list) == 1 && nb != 100)
	{
		check_and(nbr, i, nbrc);
		print_nb(nb, begin_list);
		if (nb >= 20 && nb <= 99)
			ft_putchar(' ');
	}
	else
		print_hundreds(nbr, nbrc, i, begin_list);
}
