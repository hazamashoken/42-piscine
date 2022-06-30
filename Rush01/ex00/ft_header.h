/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:11:38 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/19 01:38:40 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

void	ft_putchar(char c);

void	ft_putstr(char *str);

int		ft_get_size(char *str);

char	**ft_init_tab(char *str, int size);

int		ft_solve(char **tab, int size);

void	ft_print_tab(char **tab, int size);

void	ft_destroy_tab(char **tab, int size);

int		ft_height_col(char **tab, int x, int delta, int size);

int		ft_height_row(char **tab, int y, int delta, int size);

int		ft_is_duplicate(char **tab, int x, int y, int size);

#endif
