/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 21:04:06 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/20 18:28:41 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	lcm_recur(unsigned int r_a, unsigned int r_b, unsigned int c_a, unsigned int c_b)
{

	if (c_a < c_b)
		return (lcm_recur(r_a, r_b, (r_a + c_a), c_b));
	else if (c_a > c_b)
		return (lcm_recur(r_a, r_b, c_a, (r_b + c_b)));
	return (c_a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return (lcm_recur(a, b, a, b));
}
/*
int	main(void)
{
	unsigned int	res;

	res = lcm(10, 4);
	printf("%i\n", res);
	return (0);
}
*/
