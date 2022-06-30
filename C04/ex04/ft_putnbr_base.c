/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:47:22 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/16 20:15:29 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putbase(long n, char *base, int len)
{
	if (n == -2147483648)
	{
		write(1, "-", 1);
		ft_putbase(2147483648, base, len);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putbase(n * -1, base, len);
	}
	else if (n > len)
	{
		ft_putbase(n / len, base, len);
		write(1, &base[n % len], 1);
	}
	else
		write(1, &base[n % len], 1);
}

int	ft_validate_base(char *base, int len)
{
	int	i;
	int	k;

	i = 0;
	if (len <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if ((base[i] < ' ' || base[i] > '~')
			|| base[i] == '+' || base[i] == '-')
			return (0);
		k = i + 1;
		while (k < len)
		{
			if (base[i] == base[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		valid;

	if (base == 0)
		return ;
	len = ft_strlen(base);
	valid = ft_validate_base(base, len);
	if (valid)
		ft_putbase(nbr, base, len);
}
