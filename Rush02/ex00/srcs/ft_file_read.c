/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:40:01 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/26 15:18:03 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*addchar(char *str, char *buf)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = buf[0];
	new[i + 1] = '\0';
	free(str);
	return (new);
}

void	free_str(char **str)
{
	free(*str);
	*str = malloc(1);
	*str[0] = '\0';
}

int	str_free(char *str)
{
	free(str);
	return (1);
}

int	gest_buf(int file, t_dict **begin)
{
	int		size;
	char	*str;
	char	buf[1];

	str = malloc(sizeof(char));
	str[0] = '\0';
	while (1)
	{
		size = read(file, buf, 1);
		if (size == 0 && str_free(str))
			return (ft_list_sort(begin));
		if (buf[0] != '\n')
		{
			str = addchar(str, buf);
			if (!str)
				return (0);
		}
		else
		{
			if (parse_dict(begin, str) == 1)
				free_str(&str);
			else if (ft_strlen(str) != 0)
				return (0);
		}
	}
}

int	ft_file_read(char *filepath, t_dict **begin)
{
	int			file;

	file = open(filepath, O_RDWR);
	if (file != -1)
	{
		if (gest_buf(file, begin) == 0)
			return (-1);
		return (1);
	}
	else
		return (0);
}
