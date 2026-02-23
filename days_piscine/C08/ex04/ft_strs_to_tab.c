/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:30:53 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/23 23:49:46 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_set_elem(t_stock_str *arry, char **av, int len, int i)
{
	int	j;

	arry[i].str = av[i];
	arry[i].size = len;
	j = 0;
	while (j < len)
	{
		arry[i].copy[j] = av[i][j];
		j++;
	}
	arry[i].copy[j] = '\0';
	return ;
}

void	ft_free_all(t_stock_str *arry, int i)
{
	while (i >= 0)
	{
		free(arry[i].copy);
		i--;
	}
	free(arry);
	return ;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arry;
	int			len;
	int			i;

	arry = malloc((ac + 1) * sizeof(t_stock_str));
	if (!arry)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		arry[i].copy = malloc((len + 1) * sizeof(char));
		if (!arry[i].copy)
		{
			ft_free_all(arry, (i - 1));
			return (NULL);
		}
		ft_set_elem(arry, av, len, i);
		i++;
	}
	arry[ac].str = 0;
	return (arry);
}
/*
int	main(int argc, char **argv)
{
	t_stock_str	*result;
	if (argc < 2)
		return (0);

	argc -= 1;
	argv += 1;
	result = ft_strs_to_tab(argc, argv);
	printf("Word 0 copy: %s\n", result[0].copy);
	printf("Word 1 copy: %s\n", result[1].copy);
	printf("Word 1 size: %d\n", result[1].size);
	return (0);
}
*/
