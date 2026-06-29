/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_1_rotone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:30:34 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:30:35 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int	main (int ac, char *av[])
{
	int	i;
	char	*str;

	if (ac != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	str = av[1];
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = (str[i] - 'a' + 1) % 26 + 'a';
			ft_putchar(str[i]);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = (str[i] - 'A' + 1) % 26 + 'A';
			ft_putchar(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
	return 0;
}
