/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_3_rev_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:33:30 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:33:32 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	char	*str;

	if (ac == 2)
	{
		i = 0;
		str = av[1];
		while (str[i])
			i++;
		i--;
		while (i >= 0)
		{
			write(1, &str[i], 1);
			i--;
		}
		write(1, "\n", 1);
	}
	else
	{
		write(1, "\n", 1);
	}
}
