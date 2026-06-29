/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 22:33:40 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/15 23:04:54 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	int	mask;
	unsigned char	bit;

	mask = 7;
	while (mask >= 0)
	{
		bit = ((octet >> mask) & 1) + '0';
		if (mask == 3)
			write(1, "  ", 2);
		write(1, &bit, 1);
		mask--;
	}

}
*/
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int	count;

	res = 0;
	count = 7;
	while (count >= 0)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
		count--;
	}
	return (res);
}
/*
int	main(int argc, char *argv[])
{
	unsigned char	c;
	print_bits(atoi(argv[1]));
	write(1, "\n       ||\n", 11);
	write(1, "       \\/\n", 10);
	c = reverse_bits(atoi(argv[1]));
	print_bits(c);
	return (0);
}
*/
