/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:37:21 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/26 15:41:41 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

int	check_exists(t_dict *begin, int nb)
{
	while (begin)
	{
		if (begin->nb == nb)
			return (0);
		begin = begin->next;
	}
	return (1);
}

/*
@brief	seperate number into 2 set between 0 to 100 and 1000+
@brief	
*/
int	get_nb(int *nb, int *suf, char *str)
{
	int		i;
	int		j;

	i = 0;
	*nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i >= 4)
	{
		j = -1;
		if ((i - 1) % 3 != 0)
			return (0);
		while (++j < i)
			if ((j == 0 && str[j] != '1') || (j != 0 && str[j] != '0'))
				return (0);
		*nb = i / 3;
		*suf = 1;
	}
	else
		*suf = 0;
	return (1);
}

/*
@brief	check for space between	number string, :, word
@brief	return new string trimed space behind
@params	char* str	string of untrimed word
@return char*		string of trimed word
*/
char	*ft_check_space(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
			j++;
		else if (str[i - 1] != ' ')
			j++;
	}
	str2 = malloc(sizeof(char) * (j + 1));
	if (!str2)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != ' ' || str[i - 1] != ' ')
			str2[j++] = str[i];
	str2[j] = '\0';
	free(str);
	return (str2);
}

/*
@brief	check if the line is valid consist of only number
@params	char*	str	1 line from string from dict
@params	int*	i	index to start duping word into dict;
@return	int			1 if line is valid	else 0
@return	int*	i	return the index of word till unprintable
*/
int	test_line(char *str, int *i)
{
	int		j;

	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] != ':')
		return (0);
	(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	j = *i;
	while (str[++j])
		if (str[j] <= 31 || str[j] >= 127)
			return (0);
	return (1);
}

/*
@brief	take in linked list and each line from dict and add into linked list
@brief	check and clean line to extract nessessnary info from line
@params	t_dict**	begin	linked list to store the dict
@params	char*		str		1 line of string from dict
@return int					1 if success else 0
*/
int	parse_dict(t_dict **begin, char *str)
{
	int		nb;
	int		i;
	int		suf;
	char	*str2;

	if (get_nb(&nb, &suf, str) == 0)
		return (0);
	if (nb == 0)
		nb = ft_atoi(str);
	if (suf == 0 && check_exists(*begin, nb) == 0)
		return (0);
	i = 0;
	if (test_line(str, &i) == 0)
		return (0);
	str2 = ft_strdup((str + i));
	if (!str2)
		return (0);
	str2 = ft_check_space(str2);
	if (!str2)
		return (0);
	return (ft_list_push_front(begin, nb, suf, str2));
}
