/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_1_rev_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:30:13 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:30:15 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int ac, char *av[])
{
	char	*str;
	int	len;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	str = av[1];
	len = ft_strlen(str) - 1;
	while (len >= 0)
	{
		ft_putchar(str[len]);
		len--;
	}
	ft_putchar('\n');
	return 0;
}
