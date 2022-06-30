/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <tliangso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:28:49 by tliangso          #+#    #+#             */
/*   Updated: 2022/06/17 04:35:33 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define SIZE 10

int		ft_ten_queens_puzzle(void);
void	ft_putchar(char c);
int		validate(int *board, int x, int y);
void	ft_queen(int *board, int *res, int pos);

int	main(void)
{
	printf("%d", ft_ten_queens_puzzle());
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
@brief		check if the current position is a valid queen placement
@param	int*	board	current board state
@param	int		x		column number
@param	int		y		row number
@return int				1 or 0
*/
int	validate(int *board, int x, int y)
{
	int	i;

	i = -1;
	while (++i < x)
		if (y == board[i]
			|| i + board[i] == x + y
			|| i - board[i] == x - y)
			return (0);
	return (1);
}

/*
@brief		recursively check queen pos and add 1 pos till 10,
@brief		print and restart from new pos
@param	int* board	current board state
@param	int* res	the total number of solution
@param	int	pos		row number
@return	void
*/
void	ft_queen(int *board, int *res, int pos)
{
	int	i;
	int	k;

	if (pos == SIZE)
	{
		*res += 1;
		k = -1;
		while (++k < SIZE)
			ft_putchar(board[k] + '0');
		ft_putchar('\n');
	}
	else
	{
		i = -1;
		while (++i < SIZE)
		{
			if (validate(board, pos, i))
			{
				board[pos] = i;
				ft_queen(board, res, pos + 1);
			}
		}
	}
}

/*
@brief	print	all possible position of set number of queen on a N x N board
@param	void
@return	int		total number of solution
*/
int	ft_ten_queens_puzzle(void)
{
	int	board[SIZE];
	int	i;
	int	res;

	i = 0;
	while (i < SIZE)
		board[i++] = -1;
	res = 0;
	ft_queen(board, &res, 0);
	return (res);
}
