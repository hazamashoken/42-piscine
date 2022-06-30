/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:37:56 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/22 12:42:20 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));
int	ft_tri(int a, int b);

int	main(void)
{
	int	tab1[] = {0, 1, 1, 2, 3, 4};
	int	tab2[] = {4, 3, 2, 2, 1, 0};
	int	tab3[] = {4, 3, 1, 2, 1, 0};
	int	length;

	length = 6;
	printf("%d\n", ft_is_sort(tab1, length, &ft_tri));
	printf("%d\n", ft_is_sort(tab2, length, &ft_tri));
	printf("%d\n", ft_is_sort(tab3, length, &ft_tri));
}

int	ft_tri(int a, int b)
{
	return (a - b);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 1;
	while (i < length - 1 && sorted)
	{
		if ((*f)(tab[i], tab [i + 1]) < 0)
			sorted = 0;
		i++;
	}
	if (sorted != 1)
	{
		sorted = 1;
		i = 0;
		while (i < length - 1)
		{
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
