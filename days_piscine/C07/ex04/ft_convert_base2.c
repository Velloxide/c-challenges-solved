/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:05:28 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/16 15:04:15 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	is_base_valid(char *base)
{
	int	i;
	int	l;

	l = 0;
	while (base[l])
	{
		i = l + 1;
		while (base[i])
		{
			if (base[l] == base[i++])
				return (0);
		}
		if (base[l] >= 9 && base[l] <= 13)
			return (0);
		if (base[l] == ' ' || base[l] == '+' || base[l] == '-')
			return (0);
		l++;
	}
	if (l < 2)
		return (0);
	return (l);
}

static int	is_c_valid(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_count(char *str, char *base, int len)
{
	int	result;
	int	i;

	result = 0;
	while (*str)
	{
		i = is_c_valid(*str, base);
		if (i == -1)
			return (result);
		result = (result * len) + i;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	sign;

	len = is_base_valid(base);
	if (!len)
		return (0);
	while (*str >= 9 && (*str <= 13 || *str == ' '))
		str++;
	sign = 1;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (sign * (ft_count(str, base, len)));
}
/*
int	main(int argc, char **argv)
{
	int	val;

	if (argc != 3)
		return (1);
	val = ft_atoi_base(argv[1], argv[2]);
	printf("value is: %i\n", val);
	return (0);
}
*/
