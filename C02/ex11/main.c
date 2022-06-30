/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:56:28 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/15 16:32:40 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void		ft_putstr_non_printable(char *str);
static void	ft_ctohex(int np);

int	main(void)
{
	ft_putstr_non_printable("Coucou\n\t\e\r\atu vas bien ?");
	return (0);
}

static void	ft_ctohex(int np)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (np > 16)
	{
		ft_ctohex(np / 10);
		ft_ctohex(np % 10);
	}
	else
		write(1, &hex[np], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if ((*str <= 31 && *str >= 0) || *str == 127)
		{
			write(1, "\\", 1);
			if (*str < 16)
				write(1, "0", 1);
			ft_ctohex(*str);
		}
		else
			write(1, str, 1);
		str++;
	}
}
