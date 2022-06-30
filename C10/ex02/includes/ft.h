/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:54:35 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 10:47:13 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>

typedef struct s_queue
{
	char	*data;
	int		size;
	int		len;
	int		pos;
}	t_queue;

void	ft_push_queue(t_queue *f, char *bytes, int size);
int		ft_create_queue(t_queue *f, int size);
void	ft_free_queue(t_queue *f);
void	ft_print_queue(t_queue *f);
int		ft_strcmp(char *s1, char *s2);
int		ft_strnum(char *str);
void	ft_putstrf(char *str, int fd);
int		ft_print_file(char *appname, char *filename, int bytes, int print_name);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_puterr(char *str);

#endif
