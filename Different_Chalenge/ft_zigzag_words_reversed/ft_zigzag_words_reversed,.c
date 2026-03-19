/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zigzag_words_reversed,.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:07:36 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/16 20:41:41 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str, int i)
{
	while (str[i] && str[i] != ' ')
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putrevstr(char *str, int i)
{
	int	l;
	int	end;

	l = i;
	while (str[l] && str[l] != ' ')
		l++;
	end = l;
	while (l > i)
	{
		l--;
		ft_putchar(str[l]);
	}
	return (end);
}

void	ft_zigzag_words(char *str)
{
	int	i;
	int	flag;

	i = 0;
	while (str[i] == ' ')
		i++;
	flag = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (str[i] != '\0')
				ft_putchar(' ');
			flag = !flag;
		}
		if (flag == 0)
			i = ft_putstr(str, i);
		else
			i = ft_putrevstr(str, i);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	ft_zigzag_words(argv[1]);
	return (0);
}
