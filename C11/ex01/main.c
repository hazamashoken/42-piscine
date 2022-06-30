/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:36:27 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/22 10:56:12 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));
int	ft_mul(int n);

int	main(void)
{
	int	i;
	int	*tab;
	int	length;
	int	*res;

	length = 10;
	tab = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		tab[i] = i;
		i++;
	}
	res = ft_map(tab, length, &ft_mul);
	i = 0;
	while (i < length)
	{
		printf("%i", res[i]);
		i++;
	}
}

int	ft_mul(int n)
{
	return (n * 2);
}

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*res;

	res = malloc(sizeof(int) * length);
	i = -1;
	while (++i < length)
		res[i] = (*f)(tab[i]);
	return (res);
}
