/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_queens_puzzle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:08:23 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/02 23:07:45 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	is_valid(int *board, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (abs(board[i] - row) == abs(i - col))
			return (0);
		i++;
	}
	return (1);
}

void	ft_putboard(int *board, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d", board[i]);
		if (i <= n - 2)
			printf(" ");
		i++;
	}
	printf("\n");
	return ;
}

int	solve_helper(int *board, int col, int n)
{
	int	total_solutions;
	int	row;

	total_solutions = 0;
	if (col >= n)
	{
		ft_putboard(board, n);
		return (1);
	}
	row = 0;
	while (row < n)
	{
		if (is_valid(board, row, col))
		{
			board[col] = row;
			total_solutions = total_solutions + solve_helper(board, (col + 1), n);
		}
		row++;
	}
	return (total_solutions);
}

int	ft_n_queens_puzzle(int n)
{
	int	total_possible_place;
	int	*board;

	board = malloc(n * sizeof(int));
	if (board == NULL)
		return (0);
	total_possible_place = solve_helper(board, 0, n);
	free(board);
	return (total_possible_place);
}

int	main(int argc, char **argv)
{
	int	count;
	if (argc != 2)
		return (0);
	count = ft_n_queens_puzzle(atoi(argv[1]));
	printf("this is total possible place: %i\n", count);
	return (0);
}
