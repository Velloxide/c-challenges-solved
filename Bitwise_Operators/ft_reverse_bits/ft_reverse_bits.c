/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 22:18:59 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/07/04 03:12:47 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	ft_reverse_bits(unsigned char octet)
{
	int	position;
	unsigned char result;

	result = 0;
	position = 7;
	while (position >= 0)
	{
		result = result << 1;
		result = result | (octet & 1);
		octet = octet >> 1;
		position--;
	}
	return (result);
}

void	ft_print_bits(unsigned char byte)
{
	int	position;
	unsigned char	bit_value;

	position = 7;
	while (position >= 0)
	{
		bit_value = ((byte >> position) & 1 ) + '0';
		write(1, &bit_value, 1);
		position--;
	}
	write(1, "\n", 1);
}

#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	unsigned char	byte;
	if (argc != 2)
		return (0);
	byte = atoi(argv[1]);
	write(1, "Before: Value byte\n", 19);
	ft_print_bits(byte);
	byte = ft_reverse_bits(byte);
	write(1, "After: Value byte\n", 18);
	ft_print_bits(byte);
	printf("%i\n", byte);
	return (0);
}
