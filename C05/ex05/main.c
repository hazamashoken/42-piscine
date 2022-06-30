/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:39:35 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 09:22:39 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb);

int	main(void)
{
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(8));
	printf("%d\n", ft_sqrt(15));
	printf("%d\n", ft_sqrt(2147395600));
	return (0);
}

int	ft_sqrt(int nb)
{
	int	n1;
	int	n2;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	n1 = nb / 2;
	n2 = (n1 + nb / n1) / 2;
	while (n2 < n1)
	{
		n1 = n2;
		n2 = (n1 + nb / n1) / 2;
	}
	if (n1 * n1 != nb)
		return (0);
	return (n1);
}
