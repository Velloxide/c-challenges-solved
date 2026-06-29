/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 20:33:21 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/02 20:49:45 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_fprime(int nb)
{
	int	prims;
	
	while (nb % 2 == 0)
	{
		printf("2");
		nb /= 2;
		if (nb > 1)
			printf("*");
	}
	prims = 3;
	while (prims <= nb / prims)
	{
		if (nb % prims == 0)
		{
			printf("%d*", prims);
			nb /= prims;
		}
		else
			prims += 2;
	}
	if (nb > 1)
		printf("%d", nb);
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
		ft_fprime(nb);
	}
	printf("\n");
	return (0);
}
