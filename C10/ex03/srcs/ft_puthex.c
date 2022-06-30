/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:48:11 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 14:48:40 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_puthex(int nb, int pad)
{
	int		div;
	int		mod;
	char	c;

	div = nb / 16;
	mod = nb % 16;
	if (nb < 0)
	{
		ft_putchar('-');
		div = -div;
		mod = -mod;
	}
	if (div != 0 || pad > 1)
	{
		ft_puthex(div, pad - 1);
	}
	if (mod < 10)
		c = '0' + mod;
	else
		c = 'a' + (mod - 10);
	ft_putchar(c);
}

void	ft_print_hex(char *bytes, int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		ft_putstr(" ");
		if (i < size)
			ft_puthex(char_to_byte(bytes[i]), 2);
		else
			ft_putstr("  ");
		i++;
	}
}

void	ft_print_hex_c(char *bytes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i % 8 == 0)
			ft_putstr(" ");
		ft_putstr(" ");
		ft_puthex(char_to_byte(bytes[i]), 2);
		i++;
	}
}

void	ft_print_hex_text(char *bytes, int size)
{
	int	i;

	ft_putchar('|');
	i = 0;
	while (i < size)
	{
		if (bytes[i] >= 32 && bytes[i] <= 126)
			ft_putchar(bytes[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('|');
}
