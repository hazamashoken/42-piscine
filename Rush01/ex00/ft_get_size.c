/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:12:44 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 13:52:30 by tpomsati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
@brief	check if input is valid if in range (1-4) else return 0
@params	char*	str 	string of input cmdline
@params	int		size	size of the board 
@return	int				size if valid 0 if not
*/

int	ft_is_valid(char *str, int size)
{
	int	i;
	int	j;

	i = -1;
	j = size / 4;
	while (++i < size)
	{
		if (*str < '1' || *str > j + '0')
			return (0);
		str += 2;
	}
	return (j);
}

/*

@brief	determine what size of the board for the input
@brief read >> chaeck space +number >> check if size ==16 than call ft_is_valid
@brief else return invalid(0)
@params	char*	str		input from cmdline
@return	int		size of the board
*/

int	ft_get_size(char *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			size++;
		else
			return (0);
		if (str[++i] == ' ' && !str[++i])
			return (0);
	}
	if (size != 16)
		return (0);
	return (ft_is_valid(str, size));
}
