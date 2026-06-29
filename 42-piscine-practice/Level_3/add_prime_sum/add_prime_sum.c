/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:12:08 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/16 22:22:43 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	ft_putnbr(int	nb)
{
	char	res;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-",1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	res = (nb % 10) + '0';
	write(1, &res, 1);
}

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (i * i <= nb)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	nb;
	int	i;
	int	result;

	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	result = 0;
	nb = ft_atoi(argv[1]);
	if (nb > 1)
	{
		i = 2;
		while (i <= nb)
		{
			if (ft_is_prime(i))
				result += i;
			i++;
		}
	}
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
