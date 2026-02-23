/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_maze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:21:56 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/22 00:13:38 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    print_realistic_maze(char **map, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				printf("#");
			else if (map[i][j] == '0')
				printf("=");
			else if (map[i][j] == 'x')
				printf("o");
			j++;
		}
		printf("\n");
		i++;
	}
}

int	is_valid(char **map, int rows, int cols, int row, int col)
{
	if (row < 0 || col < 0 || row >= rows || col >= cols)
		return (0);
	if (map[row][col] == '1' || map[row][col] == 'x')
		return (0);
	return (1);
}

int	ft_solve_helper(char **map, int rows, int cols, int row, int col)
{

	int	result;
	char	x;

	if (is_valid(map, rows, cols, row, col) == 0)
		return (0);
	x = map[row][col];
	if ((row + 1) == rows && (col + 1) == cols)
	{
		map[row][col] = 'x';
		return (1);
	}
	map[row][col] = 'x';
	result = ft_solve_helper(map, rows, cols, row, col + 1);
	if (result)
		return (1);//for right
	result = ft_solve_helper(map, rows, cols, row + 1, col);
	if (result)
		return (1);//for down
	result = ft_solve_helper(map, rows, cols, row, col - 1);
	if (result)
		return (1);//for left
	result = ft_solve_helper(map, rows, cols, row - 1, col);
	if (result)
		return (1);//for up
	map[row][col] = x;
	return (result);
}

int	ft_solve_maze(char **map, int rows, int cols)
{
	int	result;

	result = ft_solve_helper(map, rows, cols, 0, 0);
	return (result);
}
void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ;
}

int	main(void)
{
	int	rows;
	int	cols;
	int	i;
	char	**map;

	rows = 16;
	cols = 16;
	map = malloc(rows * sizeof(char *));
	if (!map)
		return 0;
	i = 0;
	while (i < rows)
	{
		map[i] = malloc((cols + 1) * sizeof(char));
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return 0;
		}
		i++;
	}
	ft_strcpy(map[0],  "0000000000000000");
	ft_strcpy(map[1],  "1111011110111110");
	ft_strcpy(map[2],  "0000010000100000");
	ft_strcpy(map[3],  "0011111111101111");
	ft_strcpy(map[4],  "0000000100000100");
	ft_strcpy(map[5],  "0101101110110100");
	ft_strcpy(map[6],  "0101000000000100");
	ft_strcpy(map[7],  "0101011101110100");
	ft_strcpy(map[8],  "0101000000000100");
	ft_strcpy(map[9],  "0111011111010100");
	ft_strcpy(map[10], "0000010001010100");
	ft_strcpy(map[11], "0101110111010000");
	ft_strcpy(map[12], "0000000000010000");
	ft_strcpy(map[13], "1111111111110111");
	ft_strcpy(map[14], "0000100000100000");
	ft_strcpy(map[15], "0110001110001100");

	if (ft_solve_maze(map, rows, cols))
	{
		printf(">> = You can walk on it\n>> # you cannot walk on it\n>> o is the path we found\nResult:\n");
		print_realistic_maze(map, rows);
	}
	else
	{
		printf("the map:\n");
		i = 0;
		while (i < rows)
		{
			printf("%s\n", map[i]);
			i++;
		}
	}
	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}
