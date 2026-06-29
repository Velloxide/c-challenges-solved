/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_2_rotone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:32:04 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:32:06 by Itachi-Logic     ###   ########.fr       */
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

	if (ac == 2)
	{
		str = av[1];
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'y')
			{
				ft_putchar(str[i] + 1);
			}
			else if (str[i] == 'z')
			{
				ft_putchar('a');
			}
			else if (str[i] >= 'A' && str[i] <= 'Y')
			{
				ft_putchar(str[i] + 1);
			}
			else if (str[i] == 'Z')
			{
				ft_putchar('A');
			}
			else
				ft_putchar(str[i]);
			i++;
		}
	}
	else
	{
		ft_putchar('\n');
		return 0;
	}
	ft_putchar('\n');
	return 0;
}
