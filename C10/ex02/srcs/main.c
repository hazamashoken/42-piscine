/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:37:29 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 10:47:27 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_tail(int fd, int len)
{
	char	c;
	t_queue	f;

	if (!ft_create_queue(&f, len))
		return ;
	while (read(fd, &c, 1))
	{
		ft_push_queue(&f, &c, 1);
	}
	ft_print_queue(&f);
	ft_free_queue(&f);
}

int	ft_print_error(char *prog, char *file)
{
	ft_puterr(basename(prog));
	ft_puterr(": ");
	ft_puterr(file);
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	ft_puterr("\n");
	return (0);
}

int	ft_print_option_err(char *prog, char *error, char *arg)
{
	ft_puterr(basename(prog));
	ft_puterr(": ");
	ft_puterr(error);
	ft_puterr(arg);
	ft_puterr("\n");
	return (1);
}

int	ft_print_file(char *appname, char *filename, int bytes, int print_name)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (ft_print_error(appname, filename));
	else
	{
		if (print_name > 0)
		{
			if (print_name > 1)
				ft_putstr("\n");
			ft_putstr("==> ");
			ft_putstr(basename(filename));
			ft_putstr(" <==\n");
		}
		ft_print_tail(file, bytes);
		close(file);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	len;
	int	i;
	int	r;

	r = 0;
	len = -1;
	if (argc >= 3 && ft_strcmp(argv[1], "-c") == 0 && ft_strnum(argv[2]))
		len = ft_atoi(argv[2]);
	else
		return (1);
	if (len < 0)
		return (ft_print_option_err(argv[0], "illegal offset -- ", argv[2]));
	if (argc == 3)
		ft_print_tail(0, len);
	i = 3;
	while (i < argc)
	{
		if (argc == 4)
			ft_print_file(argv[0], argv[i], len, 0);
		else
			r += ft_print_file(argv[0], argv[i], len, r + 1);
		i++;
	}
	return (0);
}
