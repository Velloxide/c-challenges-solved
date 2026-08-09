/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:45:17 by saboutay          #+#    #+#             */
/*   Updated: 2026/07/31 20:29:59 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	maxSubArray(int* nums, int numsSize)
{
	int	i;
	int	max_sum;
	int	crr_maxsum;

	max_sum = nums[0];
	crr_maxsum = nums[0];
	i = 1;
	while (i < numsSize)
	{
		if (nums[i] > crr_maxsum + nums[i])
			crr_maxsum = nums[i];
		else
			crr_maxsum += nums[i];
		if (max_sum < crr_maxsum)
			max_sum = crr_maxsum;
		i++;
	}
	return (max_sum);
}

int	main(void)
{
	int	buf[5] = {5,4,-10,7,-20};

	printf("%d", maxSubArray(buf, 5));
}
