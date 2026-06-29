/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 21:15:06 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/20 22:51:35 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_HCF(unsigned int x, unsigned int y)
{
	unsigned int	temp;
	//	ft_HCF(x, y)
	//	ft_HCF(4, 6)
	//	temp	= (x = 4) % (y = 6) >> 4
	//	x	= (y = 6)
	//	y	= (temp = 4)
	temp = 1;
	while (temp != 0)
	{
		temp = x % y;
		x = y;
		y = temp;
	}
	return (x);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	if (argc == 3 && x > 0 && y > 0)
		printf("%u", ft_HCF(x, y));
	printf("\n");
	return (0);
}
