/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:16:22 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/04 21:39:09 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_getLin(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int	digit;
	int	lenNbr;
	
	lenNbr = ft_getLin(nbr);
	str = malloc((lenNbr + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[lenNbr--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
		str[0] = '-';
	while (nbr != 0)
	{
		digit = nbr % 10;
		if (digit < 0)
			digit = -digit;
		str[lenNbr] = digit + '0';
		lenNbr--;
		nbr /= 10;
	}
	return (str);
}
/*
int	main(int ac, char **av)
{
	char	*nbr;
	
	if (ac == 2)
	{
		nbr = ft_itoa(atoi(av[1]));
		printf("%s\n", nbr);
		free(nbr);
	}
	return (0);
}
*/
