/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:55:52 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/16 18:06:35 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_neg_space(char *str, int *ptr_i)
{
	int	neg;
	int	i;

	i = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	*ptr_i = i;
	return (neg);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	res;
	int	i;

	if (str == 0)
		return (0);
	res = 0;
	neg = ft_neg_space(str, &i);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}
