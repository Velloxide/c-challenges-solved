/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 19:17:01 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/08/26 20:31:19 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_print_addr(unsigned long addr)
{
	char	*hex_digits;
	int		i;
	int		digit;

	hex_digits = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		digit = (addr >> (i * 4)) & 15;
		ft_putchar(hex_digits[digit]);
		i--;
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	ft_print_content(char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			if (str[i] >= 32 && str[i] <= 126)
				ft_putchar(str[i]);
			else
				ft_putchar('.');
		}
		i++;
	}
	return ;
}

void	ft_puthex4(char *str, unsigned int size)
{
	char			*hex_digits;
	unsigned char	c;
	unsigned int	i;

	hex_digits = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			c = (unsigned char) str[i];
			ft_putchar(hex_digits[c / 16]);
			ft_putchar(hex_digits[c % 16]);
		}
		else
			write(1, "  ", 2);
		if (i % 2 != 0)
			ft_putchar(' ');
		i++;
	}
	return ;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	addrs;
	unsigned int	i;
	unsigned int	size_curr;

	i = 0;
	while (i < size)
	{
		addrs = (unsigned long) addr;
		size_curr = size - i;
		if (size_curr > 16)
			size_curr = 16;
		ft_print_addr(addrs + i);
		ft_puthex4((char *) addr + i, size_curr);
		ft_print_content((char *) addr + i, size_curr);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
/*
#include <stdlib.h>
int	main()
{
	char str[] = "bonjourlesaminslejjsdjdhhfsjfhojwdmaroclesproject";
	ft_print_memory(str, sizeof(str) - 1);
}
*/
