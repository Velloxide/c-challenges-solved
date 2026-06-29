/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:57:25 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/14 22:06:36 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 1;
	while (i < n)
		i *= 2;
	if (i == n)
		return (1);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	int	num;

	if (argc == 2)
	{
		num = is_power_of_2(atoi(argv[1]));
		printf("%i\n", num);
	}
	return (0);
}
*/
