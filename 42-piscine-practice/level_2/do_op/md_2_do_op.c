/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_2_do_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:38:44 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:38:46 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int	ft_atoi(char *str)
{
	int	i;
	int	sum;
	int	result;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sum = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sum = sum * (-1);
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sum);
}

void	ft_putnbr(int nb)
{
	char	number;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	number = (nb % 10) + '0';
	ft_putchar(number);
	return ;
}

int	ft_do_op(char av, int n1, int n2)
{
	int result;

	result = 0;
	if (av == '+')
		result = n1 + n2;
	else if (av == '-')
		result = n1 - n2;
	else if (av == '*')
		result = n1 * n2;
	else if (av == '/')
		result = n1 / n2;
	else if (av == '%')
		result = n1 % n2;
	return (result);
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int	n1;
		int	n2;
		int	result;
		
		n1 = ft_atoi(av[1]);
		n2 = ft_atoi(av[3]);
		result = ft_do_op(av[2][0], n1, n2);
		ft_putnbr(result);
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}
