/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_border_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 23:46:45 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/14 00:47:44 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_border_sum(int **matrix, int rows, int cols)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
				count += matrix[i][j];
			j++;
		}
		i++;
	}
	printf("%i\n", count);
	return (count);
}

int	main(void)
{
	int *matrix[] = {
		(int[]){10, 0, 0, 10},
		(int[]){1, 2, 2, 1},
		(int[]){10, 0, 0, 10}
	};
	ft_border_sum(matrix, 3, 4);

	return (0);
}
