/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 20:17:36 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/09 21:35:03 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *nbr)
{
	int	res;

	while (*nbr && (*nbr == ' ' || *nbr == '\t'))
		nbr++;
	res = 0;
	while (*nbr && *nbr >= '0' && *nbr <= '9')
	{
		res = (res * 10) + (*nbr - '0');
		nbr++;
	}
	return (res);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb > 9)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	ft_putres(int i, int nb, int res)
{
	ft_putnbr(i);
	write(1, " x ", 3);
	ft_putnbr(nb);
	write(1, " = ", 3);
	ft_putnbr(res);
	return ;
}

void	ft_tab_mult(int nb)
{
	int	i;
	int	res;

	i = 1;
	while (i <= 9)
	{
		res = i * nb;
		ft_putres(i, nb, res);
		i++;
		write(1, "\n", 1);
	}
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_tab_mult(ft_atoi(argv[1]));
	}
	else
		write(1, "\n", 1);
	return (0);
}
