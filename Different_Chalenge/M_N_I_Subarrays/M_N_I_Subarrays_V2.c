/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   M_N_I_Subarrays_V2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 01:44:58 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/15 23:14:24 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	minNumberOperations(int *target, int targetSize)
{
	//Input: target = [3,1,5,4,2]
	//Output: 7
	int	i;
	int	totall_move;

	totall_move = target[0];
	i = 1;
	while (i < targetSize)
	{
		if (target[i] > target[i - 1])
			totall_move += target[i] - target[i - 1];
		i++;
	}
	return (totall_move);
}

int	main(void)
{
	int	target[5] = {3,1,5,4,2};
	int	targetSize;

	targetSize = 5;
	printf("%i\n", minNumberOperations(target, targetSize));
	return (0);
}
