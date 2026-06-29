/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_1_ulstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:31:22 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:31:24 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int	main(int ac, char *av[])
{
	int	i;
	char	*str;

	if (ac == 2)
	{
		i = 0;
		str = av[1];
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				ft_putchar(str[i] - ('a' - 'A'));
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				ft_putchar(str[i] + ('a' - 'A'));
			}
			else {
				ft_putchar(str[i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return 0;
}
