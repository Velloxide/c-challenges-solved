/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:55:04 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/16 01:36:46 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/*
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
unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	temp;

	temp = (octet << 4);
	octet = (octet >> 4);
	temp |= octet;
	return (temp);
}
/*
int	main(int argc, char *argv[])
{
	unsigned char	c;
	print_bits(atoi(argv[1]));
	c = swap_bits(atoi(argv[1]));
	write(1, "\n", 1);
	print_bits(c);
	write(1, "\n", 1);
	printf("%i\n", c);
	return (0);
}
*/
