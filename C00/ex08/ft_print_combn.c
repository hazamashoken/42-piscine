/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:06:12 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/10 00:22:15 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
@brief			use write to print to console a single input char
@param	char	c 	char to be write out
@return	void
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
@brief			use ft_putchar, write out everthing in input array
@param	int	arr	array of int  to be write out as char
@param	int	n	int of array length
@return void
*/
void	ft_putarr(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_putchar(arr[i++] + 48);
}

/*
@breif			take in combn array pointer and return the index that need 
@breif 			ft_increment else return -1 to indicate last value
@param	int	*combn	array pointer point to the current combn in the while loop
@param	int	n	int of array length
*/
/*
@return	int	(i - 1) next index to ft_increment if cur digit = max val
@return int	(i)	the current index if current digit < max val
@return int	(-1)	if index = 0 and reach max val return -1 to exit loop
*/
int	ft_get_index(int *combn, int n)
{
	int	i;
	int	max;

	i = 0;
	max = 10 - n;
	while (i < n)
	{
		if (combn[i] == max)
			return (i - 1);
		if (i == (n - 1) && combn[i] < max)
			return (i);
		i++;
		max++;
	}
	return (-1);
}

/*
@breif			increase the digit of input array at the input pos_index of the array
@param	int	*combn	array pointer to the combn array
@param	int	n	int of array length
@param	int	index	array pos_index to be increment
@return	void
*/
void	ft_increment(int *combn, int n, int index)
{
	int	i;

	i = index + 1;
	combn[index]++;
	while (i <= n)
	{
		combn[i] = combn[i - 1] + 1;
		i++;
	}
}

/*
@brief			take in int indicating place value limit and write out
@brief			all posible combn of (0-9) without repeating combn
@param	int	n	int indicating place value limit of combn
@return	void
*/
void	ft_print_combn(int n)
{
	int	combn[9];
	int	i;
	int	pos_index;

	i = 0;
	while (i < n)
	{
		combn[i] = i;
		i++;
	}
	while (ft_get_index(combn, n) != -1)
	{
		pos_index = ft_get_index(combn, n);
		ft_putarr(combn, n);
		ft_increment(combn, n, pos_index);
		write(1, ", ", 2);
	}
	ft_putarr(combn, n);
}
