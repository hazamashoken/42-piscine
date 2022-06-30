/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:35:44 by abossel           #+#    #+#             */
/*   Updated: 2022/06/29 14:19:26 by abossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_libft.h"
#include "freezero.h"
#include "map.h"

/*
 * reads a line of text
 * line must be only printable chars then optional CR then NL or EOF
 * CR may be present on map files created in windows
 */
char	*read_line(int fd)
{
	char	str[10240];
	int		is_cr;
	int		i;

	i = 0;
	is_cr = 0;
	while (read(fd, &str[i], 1))
	{
		if (str[i] >= ' ' && str[i] <= '~')
		{
			i++;
		}
		else if (str[i] == '\r' && is_cr == 0)
			is_cr = 1;
		else if (str[i] == '\n')
		{
			str[i] = '\0';
			return (ft_strdup(str));
		}
		else
			return (ft_strdup(""));
	}
	str[i] = '\0';
	return (ft_strdup(str));
}

/*
 * reads the first line of the map
 * the line must be read backwards because numbers can be used for the map
 * the first character of the number must be 1 - 9
 */
int	read_map_info(int fd, t_map *map)
{
	char	*line;
	int		len;

	line = read_line(fd);
	if (line == NULL)
		return (0);
	len = ft_strlen(line);
	if (len < 4)
		return (freezero(line));
	map->full = line[len - 1];
	map->obstacle = line[len - 2];
	map->empty = line[len - 3];
	line[len - 3] = '\0';
	if (map->full == map->obstacle || map->obstacle == map->empty
		|| map->empty == map->full || line[0] < '1' || line[0] > '9')
		return (freezero(line));
	len = len - 3;
	while (--len)
		if (line[len] < '0' || line[len] > '9')
			return (0);
	map->height = ft_atoi(line);
	free(line);
	if (map->height < 1)
		return (0);
	return (1);
}

/*
 * check if a string contains all map characters
 */
int	line_check(char *str, t_map *map)
{
	while (*str != '\0')
	{
		if (*str != map->obstacle && *str != map->empty)
			return (0);
		str++;
	}
	return (1);
}

/*
 * reads the map data
 * reads each line then checks the width and contents
 * the length of the first line sets the width
 * attempt to read at the end to check for EOF
 * returns 1 on success 0 on fail.
 */
int	read_map_data(int fd, t_map *map)
{
	int		i;
	char	c;

	map->data = malloc(sizeof(char **) * map->height);
	map->data[0] = read_line(fd);
	if (ft_strlen(map->data[0]) < 1)
		return (free_map(map));
	map->width = ft_strlen(map->data[0]);
	i = 1;
	while (i < map->height)
	{
		map->data[i] = read_line(fd);
		if (ft_strlen(map->data[i]) != map->width
			|| !line_check(map->data[i], map))
			return (free_map(map));
		i++;
	}
	if (read(fd, &c, 1))
		return (free_map(map));
	return (1);
}

/*
@brief	print map to the screen
@params	t_map*	map	data structure t_map to store the info
@return non
*/
void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_putstr(map->data[i]);
		ft_putstr("\n");
		i++;
	}
}
