/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:49:08 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 09:21:25 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstrf(char *str, int fd)
{
	if (str == 0)
		return ;
	while (*str)
		write(fd, str++, 1);
}

int	main(int argc, char *argv[])
{
	char	byte;
	int		file;

	if (argc == 1)
	{
		ft_putstrf("File name missing.\n", 2);
		return (0);
	}
	if (argc > 2)
	{
		ft_putstrf("Too many arguments.\n", 2);
		return (0);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		ft_putstrf("Cannot read file.\n", 2);
		return (0);
	}
	while (read(file, &byte, 1))
		write(1, &byte, 1);
	close(file);
	return (0);
}
