/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baseV2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:50:32 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/07 15:07:03 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>


int	ft_lenGet(long value, int base)
{
	int	len;

	len = 0;
	if (value == 0)
        	return (1);
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	int		len;
	long		nb;
	char	*nbr;

	if (base == 10)
		nb = value;
	else
		nb = (unsigned int) value;
	len = ft_lenGet(nb, base);
	if (nb < 0)
	{
		nb = -nb;
		len += 1;
	}
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	if (nb == 0)
		nbr[0] = '0';
	nbr[len--] = '\0';
	while (nb != 0)
	{
		nbr[len] = "0123456789ABCDEF"[nb % base];
		nb /= base;
		len--;
	}
	if (value < 0 && base == 10)
		nbr[0] = '-';
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
