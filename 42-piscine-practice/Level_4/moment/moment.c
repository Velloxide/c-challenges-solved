/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:34:08 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/13 21:40:27 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_getproc(unsigned int dur, unsigned int proc, char **unit)
{
	unsigned int	minute;
	unsigned int	hour;
	unsigned int	day;
	unsigned int	month;

	minute = 60;
	hour = minute * 60;
	day = hour * 24;
	month = day * 30;
	if (dur >= month)
	{
		proc = month;
		*unit = "month";
	}
	else if (dur >= day)
	{
		proc = day;
		*unit = "day";
	}
	else if (dur >= hour)
	{
		proc = hour;
		*unit = "hour";
	}
	else if (dur >= minute)
	{
		proc = minute;
		*unit = "minute";
	}
	return (proc);
}

int	ft_nbrlen(int nbr)
{
	int	count;

	count = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_put_nbr_to_str(char **ptr, int count)
{
	if (count > 9)
		ft_put_nbr_to_str(ptr, count / 10);
	*(*ptr) = (count % 10) + '0';
	(*ptr)++;
}

char	*ft_fulldest(char *dest, char *unit, int count)
{
	char	*ptr;
	char	*ago;

	ptr = dest;
	if (count == 0)
		*ptr++ = '0';
	else
		ft_put_nbr_to_str(&ptr, count);
	*ptr++ = ' ';
	while (*unit)
		*ptr++ = *unit++;
	if (count != 1)
		*ptr++ = 's';
	ago = " ago.";
	while (*ago)
		*ptr++ = *ago++;
	return (dest);
}

char	*moment(unsigned int duration)
{
	char	*dest;
	char	*unit;
	unsigned int	proc;
	int		count;
	int		total_len;

	unit = "second";
	proc = ft_getproc(duration, 1, &unit);
	count = duration / proc;
	total_len = 0;
	while (unit[total_len])
		total_len++;
	total_len += ft_nbrlen(count) + 6;
	if (count != 1)
		total_len++;
	dest = malloc((total_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[total_len] = '\0';
	ft_fulldest(dest, unit, count);
	return (dest);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("%s\n", moment(atoi(argv[1])));
	return (0);
}
*/
