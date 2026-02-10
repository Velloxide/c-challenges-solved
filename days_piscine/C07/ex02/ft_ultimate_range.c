/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:03:28 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/10 19:32:32 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	len;
	int			*dest;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = (long long)max - (long long)min;
	dest = (int *) malloc(len * sizeof(int));
	if (dest == 0)
	{
		*range = NULL;
		return (-1);
	}
	*range = dest;
	while (min < max)
		*(dest++) = min++;
	return ((int)len);
}
/*
int	main(int argc, char *argv[])
{
	int	size;
	int	*dest;
	long long	len;
	long long	i;

	if (argc != 3)
		return (1);
	size = ft_ultimate_range(&dest, atoi(argv[1]), atoi(argv[2]));
	if (dest == 0)
		return (1);
	len = (long long)atoi(argv[2]) - (long long)atoi(argv[1]);
	i = 0;
	while (i < len)
	{
		printf("<%i> ", dest[i]);
		i++;
	}
	printf("\nsize of this number is: %i\n", size);
	free(dest);
	return (0);
}
*/
