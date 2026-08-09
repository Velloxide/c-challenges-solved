/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheft_k.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Velloxide <Velloxide@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 00:49:44 by Velloxide         #+#    #+#             */
/*   Updated: 2026/08/08 01:06:39 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_revers(int *buf, int start, int end)
{
	int	tmp;

	while (start < end)
	{
		tmp = buf[start];
		buf[start] = buf[end];
		buf[end] = tmp;
		start++;
		end--;
	}
}

void	ft_sheft_k(int *buf, int size, int k)
{
	k = k % size;
	ft_revers(buf, 0, size - 1);
	ft_revers(buf, 0, k - 1);
	ft_revers(buf, k, size - 1);
}


















#include <stdio.h>
int main(void)
{
	int	buf[] = {-3, 2, 7, 1, 4, 8};
	int	size;
	int	i;

	size = sizeof(buf) / sizeof(buf[0]);
	i = 0;
	while (i < size)
	{
		printf("%d ", buf[i]);
		i++;
	}
	ft_sheft_k(buf, size, 3);
	printf("\n");
	i = 0;
	while (i < size)
	{
		printf("%d ", buf[i]);
		i++;
	}
	return (0);
}
