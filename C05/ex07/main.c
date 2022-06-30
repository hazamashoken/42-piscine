/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:10:37 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 09:19:08 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	printf("%d\n", ft_find_next_prime(2));
	printf("%d\n", ft_find_next_prime(3));
	printf("%d\n", ft_find_next_prime(5));
	printf("%d\n", ft_find_next_prime(6));
	printf("%d\n", ft_find_next_prime(1453168142));
	return (0);
}

int	ft_is_prime(int nb)
{
	long	i;
	long	nbl;

	nbl = nb;
	if (nbl == 2 || nbl == 3)
		return (1);
	if (nbl <= 1 || nbl % 2 == 0 || nbl % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nbl)
	{
		if (nbl % i == 0 || nbl % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
