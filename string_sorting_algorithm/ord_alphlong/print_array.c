/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:17:39 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/27 23:19:04 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ord_tools.h"

void	ft_print_array(char **word, int size)
{
	int	k;

	k = 0;
	while (k < size)
	{
		printf("%s", word[k]);
		if (k + 1 < size)
		{
			if (ft_strlen(word[k]) == ft_strlen(word[k + 1]))
				printf(" ");
			else
				printf("\n");
		}
		k++;
	}
	printf("\n");
}
