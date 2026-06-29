/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:46:20 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/19 19:55:47 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int     *ft_range(int start, int end)
{
	int	*arry;
	int	len;
	int	i;

	len = ft_abs(end - start) + 1;
	arry = malloc(len * sizeof(int));
	if (!arry)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (start < end)
			arry[i++] = start++;
		else
			arry[i++] = start--;
	}
	return (arry);
}
/*
int	main(int c, char **v)
{
	int	*arry;
	int	i;
	int	len;

	len = abs(atoi(v[2]) - atoi(v[1])) + 1;
	arry = ft_range(atoi(v[1]), atoi(v[2]));
	if (!arry)
		return (0);
	i = 0;
	while (i < len)
		printf("%d ", arry[i++]);
	free(arry);
	return (0);
}
*/
