/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:35:44 by abossel           #+#    #+#             */
/*   Updated: 2022/06/28 09:29:53 by abossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	full;
	char	**data;
}	t_map;

/*
 * clear a map
 * doesn't free memory;
 */
void	clear_map(t_map *map);

/*
 * frre map memory
 */
int		free_map(t_map *map);

/*
 * reads a line of text
 * line must be only printable chars then optional CR then NL or EOF
 * CR may be present on map files created in windows
 */
char	*read_line(int fd);

/*
 * reads the first line of the map
 * the line must be read backwards because numbers can be used for the map
 * the first character of the number must be 1 - 9
 */
int		read_map_info(int fd, t_map *map);

/*
 * reads the map data
 * reads each line then checks the width and contents
 * the length of the first line sets the width
 * attempt to read at the end to check for EOF
 * returns 1 on success 0 on fail.
 */
int		read_map_data(int fd, t_map *map);

/*
@brief	print map to the screen
@params	t_map*	map	data structure t_map to store the info
@return non
*/
void	print_map(t_map *map);

#endif
