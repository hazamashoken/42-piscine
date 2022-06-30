/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:57:15 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/16 15:03:26 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_is_prime(int nb);
void	test(int nb);

int	main(void)
{
	test(5);
	test(10);
	test(1);
	test(2);
	return (0);
}

void	test(int nb)
{
	if (ft_is_prime(nb))
		printf("%d is prime num\n", nb);
	else
		printf("%d is not prime num\n", nb);
}

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
