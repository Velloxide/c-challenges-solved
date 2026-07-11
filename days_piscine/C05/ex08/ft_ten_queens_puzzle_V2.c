/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle_V2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:08:23 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/07/01 21:03:02 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	is_valid(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (ft_abs(board[i] - row) == ft_abs(i - col))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_putboard(int *board)
{
	int	i;
	int	c;

	i = 0;
	while (i <= 9)
	{

		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return ;
}

static int	solve_helper(int *board, int col)
{
	int	total_solutions;
	int	row;

	total_solutions = 0;
	if (col >= 10)
	{
		ft_putboard(board);
		return (1);
	}
	row = 0;
	while (row < 10)
	{
		if (is_valid(board, row, col))
		{
			board[col] = row;
			total_solutions = total_solutions + solve_helper(board, (col + 1));
			board[col] = -1;
		}
		row++;
	}
	return (total_solutions);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	total_possible_place;
	int	board[10];

	i = 0;
	while (i < 10)
	{
		board[i] = -1;
		i++;
	}
	total_possible_place = solve_helper(board, 0);
	return (total_possible_place);
}

int	main(void)
{
	int	total_solutions;

	total_solutions = ft_ten_queens_puzzle();
	printf("total_solutions: %i\n", total_solutions);
	return (0);
}
