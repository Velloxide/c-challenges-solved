/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_argv_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:27:44 by saboutay          #+#    #+#             */
/*   Updated: 2026/07/27 22:42:02 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main (int ac, char *av[])
{
	
	int	i;
	int	j;
	int	nb1;
	int	nb2;
	char	*ptr;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (j < ac - i)
		{
			nb1 = atoi(av[j]);
			nb2 = atoi(av[j + 1]);
			if (nb1 > nb2)
			{
				ptr = av[j];
				av[j] = av[j + 1];
				av[j + 1] = ptr;
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		printf("%s\n", av[i]);
		i++;
	}
}

