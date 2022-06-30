/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:51:51 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 15:35:40 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	g_total;
int	g_c_type;

int	ft_open_file(char *appname, char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		ft_puterr(basename(appname));
		ft_puterr(": ");
		ft_puterr(filename);
		ft_puterr(": ");
		ft_puterr(strerror(errno));
		ft_puterr("\n");
	}
	else
		g_total++;
	return (file);
}

void	read_file(int fd, t_hexqueue *hq)
{
	char	c;

	while (read(fd, &c, 1))
	{
		hq_add(hq, c);
	}
}

void	error(char *program, char *filename, char *message)
{
	ft_puterr(basename(program));
	ft_puterr(": ");
	ft_puterr(filename);
	ft_puterr(": ");
	ft_puterr(message);
	ft_puterr("\n");
}

int	main(int argc, char **argv)
{
	t_hexqueue	hq;
	int			file;
	int			i;

	g_c_type = 0;
	if (argc >= 2 && ft_strcmp(argv[1], "-C") == 0)
		g_c_type = 1;
	hq_new(&hq, g_c_type);
	if (argc == 1 || (argc == 2 && g_c_type))
		read_file(0, &hq);
	i = 1 + g_c_type;
	while (i < argc)
	{
		file = ft_open_file(argv[0], argv[i++]);
		if (file != -1)
		{
			read_file(file, &hq);
			close(file);
		}
	}
	hq_flush(&hq);
	hq_print_final(&hq);
	if (g_total == 0 && ((g_c_type && argc > 2) || (!g_c_type && argc > 1)))
		error(argv[0], argv[argc - 1], "Bad file descriptor");
	return (0);
}
