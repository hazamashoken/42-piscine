/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:54:35 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/30 10:47:09 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <libgen.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strnum(char *str);
void	ft_putstrf(char *str, int fd);
void	ft_print_file(int fd);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_puterr(char *str);

#endif
