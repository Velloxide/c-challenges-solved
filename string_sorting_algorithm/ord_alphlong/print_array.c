/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:17:39 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/28 23:27:07 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ord_tools.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_pustr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_print_array(char **word, int size)
{
	int	k;

	k = 0;
	while (k < size)
	{
		ft_pustr(word[k]);
		if (k + 1 < size)
		{
			if (ft_strlen(word[k]) == ft_strlen(word[k + 1]))
				ft_putchar(' ');
			else
				ft_putchar('\n');
		}
		k++;
	}
	ft_putchar('\n');
}
