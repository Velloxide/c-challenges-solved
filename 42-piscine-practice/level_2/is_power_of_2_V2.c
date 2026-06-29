/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2_V2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:07:42 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/14 22:28:32 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	int	res;

	if (n == 0)
		return (0);
	res = ((n & (n - 1)) == 0);
	return (res);
}
/*
int	main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%i\n", is_power_of_2(atoi(argv[1])));
	return (0);
}
*/
