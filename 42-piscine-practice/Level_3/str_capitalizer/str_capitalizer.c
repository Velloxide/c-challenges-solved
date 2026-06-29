/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 20:17:01 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/22 18:26:56 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isChar(char c)
{
	if ((c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

int	ft_isSpace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	ft_str_capitalizer(char *str)
{
	int	state;

	state = 1;
	while (*str)
	{
		if (ft_isSpace(*str))
			state = 1;
		else
		{
			if (state == 1)
			{
				if (ft_isChar(*str) == 1)
					*str -= 32;
				state = 0;
			}
			else
				if (ft_isChar(*str) == 2)
					*str += 32;
		}
		write(1, str, 1);
		str++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			ft_str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
