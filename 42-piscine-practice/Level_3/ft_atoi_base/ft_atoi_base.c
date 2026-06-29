/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:03:38 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/09 21:32:12 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

int	get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return ((c - 'a') + 10);
	else if (c >= 'A' && c <= 'F')
		return ((c - 'A') + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	res;
	int	sign;
	int	value;

	if (str_base > 16 || str_base < 2)
		return (0);
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	res = 0;
	while (*str)
	{
		value = get_value(*str);
		if (value == -1 || value >= str_base)
			return (sign * res);
		res = (res * str_base) + value;
		str++;
	}
	return (sign * res);
}
/*
int	main(int argc, char *argv[])
{
	int	nb;
	int	res;

	if (argc == 3)
	{
		nb = atoi(argv[2]);
		res = ft_atoi_base(argv[1], nb);
		printf("%i\n", res);
	}
	return (0);
}
*/
