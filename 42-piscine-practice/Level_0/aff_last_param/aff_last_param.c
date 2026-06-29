/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:25:50 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:25:53 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (av[ac - 1][i])
	{
		write(1, &av[ac - 1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
