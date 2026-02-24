/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:06:52 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/24 22:23:59 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
	return ;
}

void	ft_putnbr(int nb)
{
	int	result;

	if (nb > 9)
		ft_putnbr(nb / 10);
	result = nb % 10 + '0';
	ft_putchar(result);
	return ;
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		i++;
	}
	return ;
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
	ft_show_tab(result);
	return (0);
}
*/
