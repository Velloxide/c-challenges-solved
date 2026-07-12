/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Velloxide <Velloxide@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 23:41:08 by Velloxide         #+#    #+#             */
/*   Updated: 2026/07/12 01:55:24 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_digt_sum(int num, int *res)
{
	while (num != 0)
	{
		*res += num % 10;
		num = num / 10;
	}
	if (*res > 9)
	{
		num = *res;
		*res = 0;
		ft_digt_sum(num, res);
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int	num;
	int	res;

	res = 0;
	num = atoi(argv[1]);
	ft_digt_sum(num, &res);
	printf("%i\n", res);
	return (0);
}
