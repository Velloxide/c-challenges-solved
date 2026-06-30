/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory_v2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Velloxide <Velloxide@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:17:31 by Velloxide         #+#    #+#             */
/*   Updated: 2026/06/30 21:20:57 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printaddr(unsigned long addr)
{
	char	*buf;
	int	i;
	char	c;
	
	buf = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		c = buf[(addr >> (i * 4) & 15)];
		write(1, &c, 1);
		i--;
	}
	write(1, ": ", 2);
}

void	ft_printhex(unsigned char *str, unsigned int size)
{
	unsigned int	i;
	unsigned char	*buf;

	buf = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			write(1, &buf[str[i] / 16], 1);
			write(1, &buf[str[i] % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2 != 0)
			write(1, " ", 1);
		i++;
	}
}

void	ft_putstr(char *str, unsigned int size)
{
	unsigned int	i;
	
	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			if (str[i] >= 32 && str[i] <= 126)
				write(1, &str[i], 1);
			else
				write(1, ".", 1);
		}
		i++;
	}
}

void	*print_memory_v2(void *addr, unsigned int size)
{
	unsigned int	crr_size;
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		crr_size = size - i;
		ft_printaddr((unsigned long) addr + i);
		ft_printhex((unsigned char *)addr + i, crr_size);
		ft_putstr((char *)addr + i, crr_size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

#include <stdlib.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
		print_memory_v2((void *)argv[1], atoi(argv[2]));
	return (0);
}
