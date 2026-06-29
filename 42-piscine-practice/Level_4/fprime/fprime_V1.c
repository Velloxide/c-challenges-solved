/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime_V1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 20:33:21 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/02 20:49:50 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_fprime(int nb)
{
	int	prims;

	prims = 2;
	while (prims < nb)
	{
		if (nb % prims == 0)
		{
			printf("%d*", prims);
			nb /= prims;
		}
		else
			prims++;
	}
	printf("%d", prims);
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
		ft_fprime(nb);
	}
	printf("\n");
	return (0);
}
