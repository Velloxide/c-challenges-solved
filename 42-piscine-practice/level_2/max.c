/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 01:43:49 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/15 02:03:54 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	int	old;
	int	i;

	if (len == 0)
		return (0);
	old = tab[0];
	i = 1;
	while (i < len)
	{
		if (old < tab[i])
			old = tab[i];
		i++;
	}
	return (old);
}

int	main(int argc, char *argv[])
{
	int	tab[9] = {1,2,3,4,9,5,6,7,8};
	printf("%i\n", max(tab, 9));
	return (0);
}
