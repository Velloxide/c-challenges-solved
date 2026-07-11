/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 20:33:04 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/07/08 23:27:40 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_is_valid(char *board, int col, int row)
{
	int	i;
	int	diff;

	i = 0;
	while (i < col)
	{
		if (board[i] > row)
			diff = board[i] - row;
		else
			diff = row - board[i];
		if (board[i] == row || diff == (col - i))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_putboard(char *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

static int	ft_solve(char *board, int col)
{
	int	row;
	int	count;

	count = 0;
	if (col >= 10)
	{
		ft_putboard(board);
		return (1);
	}
	row = 0;
	while (row <= 9)
	{
		if (ft_is_valid(board, col, row))
		{
			board[col] = row;
			count = count + ft_solve(board, col + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	char	board[10];

	count = ft_solve(board, 0);
	return (count);
}
/*
int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
*/
