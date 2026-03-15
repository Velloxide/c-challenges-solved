/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_N_I_Subarrays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 23:55:13 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/15 01:35:20 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_same(int *target, int *initial, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (target[i] != initial[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve_helpe(int *target, int *initial, int size, int i)
{
	int	totall_move;
	int	j;
	int	k;

	totall_move = 0;
	if (ft_is_same(target, initial, size))
	{
		k = 0;
		while (k < size)
		{
			printf("%d ", initial[k]);
			k++;
		}
		return (0);
	}
	while (i < size && initial[i] == target[i])
		i++;
	j = i;
	while (j < size && initial[j] < target[j])
		j++;
	k = i;
	while (k < j)
	{
		initial[k] += 1;
		k++;
	}
	totall_move += 1 + ft_solve_helpe(target, initial, size, i);
	return (totall_move);
}

int	minNumberOperations(int *target, int targetSize)
{
	//Input: target = [3,1,5,4,2]
	//Explanation:    [0,0,0,0,0]
	//
	//->              [1,1,1,1,1]
	//->              [2,1,1,1,1]
	//->              [3,1,1,1,1]
	//->              [3,1,2,2,2]
	//->              [3,1,3,3,2]
	//->              [3,1,4,4,2]
	//->              [3,1,5,4,2]
	//Output: 7

	int	totall_move;
	int	i;
	int	*initial;

	initial = malloc((targetSize + 1)* sizeof(int));
	if (!initial)
		return (0);
	i = 0;
	while (i < targetSize)
	{
		initial[i] = 0;
		i++;
	}
	totall_move = ft_solve_helpe(target, initial, targetSize, 0);
	free(initial);
	return (totall_move);
}

int	main(void)
{
	int	target[5] = {3,1,5,4,2};
	int	targetSize;

	targetSize = 5;
	printf("\n%i\n", minNumberOperations(target, targetSize));
	return (0);
}
