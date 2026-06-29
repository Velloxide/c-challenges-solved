/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_2_alpha_mirror.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:38:26 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:38:29 by Itachi-Logic     ###   ########.fr       */
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

	if (ac != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	i = 0;
	str = av[1];
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar((25 - (str[i] - 'A')) + 'A');
		else if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar((25 - (str[i] - 'a')) + 'a');
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
	return 0;
}
