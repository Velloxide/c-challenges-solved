/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime_V3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 20:33:21 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/02 20:50:16 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_fprime(int nb, int prims)
{
	if (nb == 1)
		return ;
	if (prims > nb / prims)
	{
		printf("%d", nb);
		return ;
	}
	if (nb % prims == 0)
	{
		printf("%d*", prims);
		ft_fprime(nb / prims, prims);
		return ;
	}
	ft_fprime(nb, prims + 2);
	return ;
}

int	main(int argc, char *argv[])
{
	int	nb;

	if (argc == 2)
	{
		nb = atoi(argv[1]);
		if (nb == 1)
		{
			printf("1\n");
			return (0);
		}
		while (nb % 2 == 0)
		{
			printf("2");
			nb /= 2;
			if (nb > 1)
				printf("*");
		}
		ft_fprime(nb, 3);
	}
	printf("\n");
	return (0);
}
