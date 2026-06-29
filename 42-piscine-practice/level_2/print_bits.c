/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:08:30 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/15 22:28:27 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	int	mask;
	unsigned char	bit;
	
	mask = 7;
	while (mask >= 0)
	{
		bit = ((octet >> mask) & 1) + '0';
		write(1, &bit, 1);
		mask--;
	}

}
/*
int	main(int argc, char *argv[])
{
	if (argc == 2)
		print_bits(atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
*/
