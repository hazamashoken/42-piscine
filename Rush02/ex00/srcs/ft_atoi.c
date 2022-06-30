/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:55:52 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/26 12:24:33 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
@brief	get the pointer pass all spaces (e.g. nl, sp)
@brief 	get pass all + and -  and determine if the input is negative.
@params char*	str	the input string
@params int*	ptr_i	the pointer to pass the real starting digits of num
@return int	neg	1 if input is positive -1 if input is negative
*/
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
/*
@brief	convert sting to integer
@params	char*	str		input as string
@return	int	res * neg	the result
*/

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
