/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_uper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Velloxide <Velloxide@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 20:54:01 by Velloxide         #+#    #+#             */
/*   Updated: 2026/07/12 21:42:31 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_upercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + 48;
	write(1, &c, 1);
}

void	ft_count_uper(char *str)
{
	char	*ptr;

	while (*str)
	{
		ptr = str;
		if (ft_is_upercase(*str))
		{
			while (*ptr && *str == *ptr)
				ptr++;
			if ((ptr - str) != 1)
				ft_putnbr((int)(ptr - str));
			ft_putchar(*str);
		}
		else
			ptr++;
		str = ptr;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_count_uper(argv[1]);
	write(1, "\n", 1);
	return (0);
}
