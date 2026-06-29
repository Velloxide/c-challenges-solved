/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_3_alpha_mirror.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:41:06 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:41:11 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_uprn(char c)
{
	if (c == 'N')
		ft_putchar('M');
	else if (c == 'O')
		ft_putchar('L');
	else if (c == 'P')
		ft_putchar('K');
	else if (c == 'Q')
		ft_putchar('J');
	else if (c == 'R')
		ft_putchar('I');
	else if (c == 'S')
		ft_putchar('H');
	else if (c == 'T')
		ft_putchar('G');
	else if (c == 'U')
		ft_putchar('F');
	else if (c == 'V')
		ft_putchar('E');
	else if (c == 'W')
		ft_putchar('D');
	else if (c == 'X')
		ft_putchar('C');
	else if (c == 'Y')
		ft_putchar('B');
	else if (c == 'Z')
		ft_putchar('A');
	return ;
}
void	ft_upra(char c)
{
	if (c == 'A')
		ft_putchar('Z');
	else if (c == 'B')
		ft_putchar('Y');
	else if (c == 'C')
		ft_putchar('X');
	else if (c == 'D')
		ft_putchar('W');
	else if (c == 'E')
		ft_putchar('V');
	else if (c == 'F')
		ft_putchar('U');
	else if (c == 'G')
		ft_putchar('T');
	else if (c == 'H')
		ft_putchar('S');
	else if (c == 'I')
		ft_putchar('R');
	else if (c == 'J')
		ft_putchar('Q');
	else if (c == 'K')
		ft_putchar('P');
	else if (c == 'L')
		ft_putchar('O');
	else if (c == 'M')
		ft_putchar('N');
	return ;
}

void	ft_lown(char c)
{
	if (c == 'n')
		ft_putchar('m');
	else if (c == 'o')
		ft_putchar('l');
	else if (c == 'p')
		ft_putchar('k');
	else if (c == 'q')
		ft_putchar('j');
	else if (c == 'r')
		ft_putchar('i');
	else if (c == 's')
		ft_putchar('h');
	else if (c == 't')
		ft_putchar('g');
	else if (c == 'u')
		ft_putchar('f');
	else if (c == 'v')
		ft_putchar('e');
	else if (c == 'w')
		ft_putchar('d');
	else if (c == 'x')
		ft_putchar('c');
	else if (c == 'y')
		ft_putchar('b');
	else if (c == 'z')
		ft_putchar('a');
	return ;
}
void	ft_lowa(char c)
{
	if (c == 'a')
		ft_putchar('z');
	else if (c == 'b')
		ft_putchar('y');
	else if (c == 'c')
		ft_putchar('x');
	else if (c == 'd')
		ft_putchar('w');
	else if (c == 'e')
		ft_putchar('v');
	else if (c == 'f')
		ft_putchar('u');
	else if (c == 'g')
		ft_putchar('t');
	else if (c == 'h')
		ft_putchar('s');
	else if (c == 'i')
		ft_putchar('r');
	else if (c == 'j')
		ft_putchar('q');
	else if (c == 'k')
		ft_putchar('p');
	else if (c == 'l')
		ft_putchar('o');
	else if (c == 'm')
		ft_putchar('n');
	return ;
}

int	main (int ac, char **av)
{
	int	i;
	char	*str;

	i = 0;
	if (ac == 2)
	{
		str = av[1];
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'm')
				ft_lowa(str[i]);
			else if (str[i] >= 'n' && str[i] <= 'z')
				ft_lown(str[i]);
			else if (str[i] >= 'A' && str[i] <= 'M')
				ft_upra(str[i]);
			else if (str[i] >= 'N' && str[i] <= 'Z')
				ft_uprn(str[i]);
			else
				ft_putchar(str[i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
