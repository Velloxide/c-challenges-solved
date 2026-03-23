/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exact_future_date.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:31:11 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/23 21:16:38 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_days_in_month(int month, int year)
{
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return (29);
		return (28);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (30);
	return (31);
}

int	ft_numlen(int year)
{
	int	len;

	len = 1;
	while (year > 9)
	{
		year /= 10;
		len++;
	}
	return (len);
}

void	ft_full_str(char *str, int d, int m, int y)
{
	int	i;

	str[0] = (d / 10) + '0';
	str[1] = (d % 10) + '0';
	str[2] = '/';
	str[3] = (m / 10) + '0';
	str[4] = (m % 10) + '0';
	str[5] = '/';
	i = 5 + ft_numlen(y);
	while (i > 5)
	{
		str[i] = (y % 10) + '0';
		y /= 10;
		i--;
	}
}

int	ft_is_valid(int d, int m, int y, long long d_t_a)
{
	if (m < 1 || m > 12 || d_t_a < 0)
		return (0);
	if (d > ft_days_in_month(m, y) || d < 1)
		return (0);
	return (1);
}

char	*ft_exact_future_date(int day, int month, int year, long long days_to_add)
{
	char	*str;

	if (!ft_is_valid(day, month, year, days_to_add))
		return (NULL);
	year = year + ((days_to_add / 146097) * 400);
	days_to_add = days_to_add % 146097;
	while (days_to_add-- > 0)
	{
		if (++day > ft_days_in_month(month, year))
		{
			day = 1;
			if (++month > 12)
			{
				year++;
				month = 1;
			}
		}
	}
	str = malloc((7 + ft_numlen(year)) * sizeof(char));
	if (!str)
		return (NULL);
	str[6 + ft_numlen(year)] = '\0';
	ft_full_str(str, day, month, year);
	return (str);
}

int	main(int argc, char *argv[])
{
	char		*str;
	int			day;
	int			month;
	int			year;
	long long	days_to_add;

	if (argc != 5)
		return (0);
	day = atoi(argv[1]);
	month = atoi(argv[2]);
	year = atoi(argv[3]);
	days_to_add = atoll(argv[4]);
	str = ft_exact_future_date(day, month, year, days_to_add);
	if (!str)
		return (0);
	printf("%s\n", str);
	free(str);
	return (0);
}
