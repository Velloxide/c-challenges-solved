/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxProfit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:55:55 by saboutay          #+#    #+#             */
/*   Updated: 2026/07/22 21:03:20 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	maxProfit(int *prices, int pricesSize)
{
	int	i;
	int	min_price;
	int	max_profit;

	min_price = prices[0];
	max_profit = 0;
	i = 1;
	while (i < pricesSize)
	{
		if (min_price > prices[i])
			min_price = prices[i];
		else if (prices[i] - min_price > max_profit)
			max_profit = prices[i] - min_price;
		i++;
	}
	return (max_profit);
}

#include <stdio.h>
int	main(void)
{
	int	res;
	int	buf[6] = {7, 1, 5, 3, 6, 4};

	res = maxProfit(buf, 6);
	printf("%d", res);
}
