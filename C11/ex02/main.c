/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:03:07 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/22 11:16:30 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char*));
int	ft_is_a(char *str);

int	main(void)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc(3 * sizeof(char *));
	array[0] = "A";
	array[1] = "Z";
	array[2] = NULL;
	while (i < 3)
	{
		printf("%d\n", ft_any(&array[i], ft_is_a));
		i++;
	}
}

int	ft_is_a(char *str)
{
	if (*str == 'A')
		return (1);
	return (0);
}

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
