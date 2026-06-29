/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm_v2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:56:15 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/20 18:35:37 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int	res;

	if (a == 0 || b == 0)
		return (0);
	else if (a >= b)
		res = a;
	else
		res = b;
	while (res)
	{
		if (res % a == 0 && res % b == 0)
			return (res);
		res++;
	}
	return (0);
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
