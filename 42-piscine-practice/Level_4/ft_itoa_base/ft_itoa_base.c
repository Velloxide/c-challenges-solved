/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:50:32 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/07 20:48:41 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_getLen(int nbr, int base)
{
	int		len;
	unsigned int	value;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0 && base == 10)
		len = 1;
	if (nbr < 0 && base == 10)
		value = -(unsigned int)nbr;
	else
		value = (unsigned int)nbr;
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	ft_getdigit(int digit)
{
	if (digit <= 9)
		return (digit +'0');
	return ((digit - 10) + 'A');
}

char	*ft_itoa_base(int value, int base)
{
	char		*nbr;
	int		len;
	unsigned int	u_value;
	unsigned int	digit;

	len = ft_getLen(value, base);
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[len--] = '\0';
	if (value == 0)
		nbr[0] = '0';
	else if (value < 0 && base == 10)
		nbr[0] = '-';
	if (value < 0 && base == 10)
		u_value = -(unsigned int)value;
	else
		u_value = (unsigned int)value;
	while (u_value != 0)
	{
		digit = u_value % base;
		nbr[len] = ft_getdigit(digit);
		u_value /= base;
		len--;
	}
	return (nbr);
}
/*
int	main(int argc, char *argv[])
{
	char	*newNbr;
	int	value;
	int	base;

	if (argc == 3)
	{
		value = atoi(argv[1]);
		base = atoi(argv[2]);
		newNbr = ft_itoa_base(value, base);
		printf("%s\n", newNbr);
	}
	return (0);
}
*/
