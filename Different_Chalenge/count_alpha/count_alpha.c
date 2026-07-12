/*                                                                            */
/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Velloxide <Velloxide@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 18:11:32 by Velloxide         #+#    #+#             */
/*   Updated: 2026/07/12 19:21:42 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_count_char(unsigned char *str, unsigned char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count += 1;
		i++;
	}
	return (count);
}

void	ft_putnbr(int nb)
{
	char	cn;

	if (nb > 9)
		ft_putnbr(nb / 10);
	cn = nb % 10 + '0';
	write(1, &cn, 1);
}

int	ft_ischar(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	ft_count_alpha(unsigned char *str)
{
	unsigned char	buf[256] = {0};
	int	count;
	int	i;
	int access;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	access = 0;
	i = 0;
	while (str[i])
	{
		if (ft_ischar(str[i]) && !buf[str[i]])
		{
			if(access)
				write(1, ", ", 2);
			count = ft_count_char(str, str[i]);
			ft_putnbr(count);
			ft_putchar(str[i]);
			buf[str[i]] = 1;
			access = 1;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ft_count_alpha((unsigned char *)argv[1]);
	write(1, "\n", 1);
	return (0);
}
