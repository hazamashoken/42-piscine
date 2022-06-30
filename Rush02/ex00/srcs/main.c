/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:35:31 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/26 15:13:16 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

/*
@brief	take in char number input and dict filepath and check for valid argc
@params	int		argc	argument counts
@params	char**	argv	argument value
@params	char**	nb		string number to be pass from argv
@params	char**	dictpatch	pointer to dictpath address to be use
@return	int					return 1 if sucess else 0
*/
int	gest_argv(int argc, char **argv, char **nb, char **dictpath)
{
	if (argc == 2)
	{
		*dictpath = "dicts/numbers.dict";
		*nb = argv[1];
		return (1);
	}
	else if (argc == 3)
	{
		*dictpath = argv[1];
		*nb = argv[2];
		return (1);
	}
	return (0);
}

/*
@brief	check if the nubmer string is a valid number string 0 - 9
@params	char* nb	number string
@return int			1 if valid else 0
*/
int	test_nb(char *nb)
{
	int		i;

	i = -1;
	while (nb[++i])
		if (nb[i] < '0' || nb[i] > '9')
			return (0);
	return (1);
}

/*
@brief	check if argv input is valid, if valid then pass over the num string
@brief	check_number after checking if defalut/inputed dict is valid else err
@params	int		argc 
@params	char**	argv	input from Stdin
@return	int				program exit state
*/
int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	*nb;
	char	*dictpath;

	if (gest_argv(argc, argv, &nb, &dictpath) == 0 || test_nb(nb) == 0)
		ft_putstr("Error\n");
	else
	{
		dict = 0;
		if (ft_file_read(dictpath, &dict) == 1)
			check_number(nb, dict);
		else
			ft_putstr("Dict Error\n");
	}
	ft_list_clear(&dict);
	return (0);
}
