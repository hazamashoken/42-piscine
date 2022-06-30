/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:18:49 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/26 13:25:31 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/*
@brief	check if num string 
*/
int	first_check(char *nbr, int *i, int *j, t_dict *begin_list)
{
	int		k;
	int		nb;
	char	nbr2[4];

	k = 0;
	while (nbr[*i] == '0')
		(*i)++;
	if (*j % 3 != 0)
	{
		while (*j % 3 != 0 || *j == 0)
		{
			nbr2[k++] = nbr[(*i)++];
			(*j)--;
		}
		nbr2[k] = '\0';
		send_to_print((nb = ft_atoi(nbr2)), begin_list, *i, nbr);
		if (*j == 0)
		{
			ft_putchar('\n');
			return (0);
		}
		if (*j >= 3)
			print_suff(*i, nbr, *j / 3, begin_list);
	}
	return (1);
}

/*
@brief	
*/
void	make_three(int i, int j, char *nbr, t_dict *begin_list)
{
	int		nb;
	int		k;
	char	nbr2[4];

	while (j > 0)
	{
		k = 0;
		while (k != 3)
		{
			nbr2[k] = nbr[i];
			i++;
			j--;
			k++;
		}
		nbr2[k] = '\0';
		nb = ft_atoi(nbr2);
		if (nb != 0)
		{
			send_to_print(nb, begin_list, i, nbr);
			if (j >= 3)
				print_suff(i, nbr, j / 3, begin_list);
		}
	}
}

/*
@brief	check if number length is valid (excluded leading 0)
@brief	check if number is 0 then printf tail node
@brief	check if number is lower than a thousand and there are valid key pair
@brief	
@params	char* 	nbr			num string
@params	t_dict*	begin_list	linked list for storing parsed value from dict
@return	int					return 0 to nothing (may change to void type)
*/
int	check_number(char *nbr, t_dict *begin_list)
{
	int		i;
	int		j;
	int		k;
	int		nb;

	i = 0;
	nb = 0;
	k = 0;
	j = check_length(nbr);
	if (j > 3 && check_suff((j - 1) / 3, begin_list) == 0)
		return (0);
	if (ft_atoi(nbr) == 0)
	{
		while (begin_list->next != NULL)
			begin_list = begin_list->next;
		ft_putstr(begin_list->literal);
		return (0);
	}
	if (first_check(nbr, &i, &j, begin_list) == 0)
		return (0);
	make_three(i, j, nbr, begin_list);
	ft_putchar('\n');
	return (0);
}
