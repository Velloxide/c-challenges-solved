/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 17:07:05 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/21 19:21:16 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned int nb)
{
	char *hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_print_hex(nb / 16);
	write(1, &hex[nb % 16], 1);
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	res;

	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	res = 0;
	while (*str && (*str >= '0' && *str <= '9'))
		res = (res * 10) + (*str++ - '0');
	return (res);
}

int	main(int argc, char *argv[])
{
	unsigned int	nb;

	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		ft_print_hex(nb);
	}
	write(1, "\n", 1);
	return (0);
}
