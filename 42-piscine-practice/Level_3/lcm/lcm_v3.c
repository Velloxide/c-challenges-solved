/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm_v3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:36:04 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/21 16:47:19 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

/*
 *				hcf(x, y) = hcf(4, 6)
 *				temp	  = 4 % 6 = 4
 *				x = 4 >>\/= 6	  = 6
 *				y = 6 >>/\= 4	  = 4
*/

unsigned int	ft_hcf(unsigned int x, unsigned int y)
{
	unsigned int	temp;

	while (y != 0)
	{
		temp = x % y;
		x = y;
		y = temp;
	}
	return (x);
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int	hcf;

	if (a == 0 || b == 0)
		return (0);
	return ((a * b) / ft_hcf(a, b));
}
/*
int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%i\n", lcm(atoi(argv[1]), atoi(argv[2])));
	}
	return (0);
}
*/
