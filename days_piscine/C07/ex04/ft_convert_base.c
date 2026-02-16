/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:18:32 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/16 16:49:27 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	is_base_valid(char *base);
int	ft_atoi_base(char *nbr, char *base);

static int	ft_nbr_len(long dec_nb, int len_base)
{
	int	len_nb;

	if (dec_nb < 0)
	{
		dec_nb *= -1;
		len_nb = 1;
	}
	else
		len_nb = 0;
	while (dec_nb >= len_base)
	{
		dec_nb /= len_base;
		len_nb++;
	}
	return (len_nb + 1);
}

char	*ft_itoa_base(char *base_to, int len_base_to, long dec_nb, int len_nb)
{
	char	*buffer;
	int		i;

	buffer = malloc((len_nb * sizeof(char)) + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[len_nb] = '\0';
	i = len_nb - 1;
	if (dec_nb < 0)
	{
		buffer[0] = '-';
		dec_nb *= -1;
	}
	if (dec_nb == 0)
		buffer[0] = base_to[0];
	while (dec_nb > 0)
	{
		buffer[i--] = base_to[dec_nb % len_base_to];
		dec_nb /= len_base_to;
	}
	return (buffer);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len_base_to;
	int		len_nb;
	long	dec_nb;

	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (NULL);
	len_base_to = is_base_valid(base_to);
	dec_nb = ft_atoi_base(nbr, base_from);
	len_nb = ft_nbr_len(dec_nb, len_base_to);
	return (ft_itoa_base(base_to, len_base_to, dec_nb, len_nb));
}
/*
int	main(int argc, char **argv)
{
	char	*buffer;
	if (argc != 4)
		return (1);
	buffer = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("the number %s from base %s to base %s is ==> %s\n",
	argv[1], argv[2], argv[3], buffer);
}
*/
