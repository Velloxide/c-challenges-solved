/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mismatch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 22:29:17 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/19 00:16:12 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*findErrorNums(int *nums, int numsSize, int *returnSize)
{
	int	i;
	long	expected_sum;
	long	nums_sum;
	long long	expected_sq_sum;
	long long	nums_sq_sum;
	long long	diff_sum;
	long long	diff_sq_sum;
	long long	sum_x_y;
	int	*output;


	output = malloc(2 * sizeof(int));
	if (!output)
		return (NULL);
	expected_sum = (long) numsSize * (numsSize + 1) / 2;
	expected_sq_sum = (long long) numsSize * (numsSize + 1) * (2 * numsSize + 1) / 6;
	nums_sum = 0;
	nums_sq_sum = 0;
	i = 0;
	while (i < numsSize)
	{
		nums_sum += nums[i];
		nums_sq_sum += (long long) nums[i] * nums[i];
		i++;
	}
	diff_sum = expected_sum - nums_sum;
	diff_sq_sum = expected_sq_sum - nums_sq_sum;
	sum_x_y = diff_sq_sum / diff_sum;
	output[1] = (diff_sum + sum_x_y) / 2;
	output[0] = sum_x_y - output[1];
	*returnSize = 2;
	return (output);
}

int	main(void)
{
	int	i;
	int	nums[9] = {1,8,9,7,9,6,3,2,4};
	int	*output;

	i = 0;
	while (i < 9)
	{
		printf("%i ", nums[i]);
		i++;
	}
	output = findErrorNums(nums, 9, nums);
	printf("\n%i ", output[0]);
	printf("%i\n", output[1]);
	return (0);
}
