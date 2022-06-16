/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:02:37 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/16 12:13:18 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	printf("%d\n", ft_iterative_factorial(0));
	printf("%d\n", ft_iterative_factorial(1));
	printf("%d\n", ft_iterative_factorial(5));
	printf("%d\n", ft_iterative_factorial(-1));
	return (0);
}

int	ft_iterative_factorial(int nb)
{
	int	res;
	int	i;

	i = 1;
	res = 1;
	if (nb < 0)
		return (0);
	while (nb--)
		res *= i++;
	return (res);
}
