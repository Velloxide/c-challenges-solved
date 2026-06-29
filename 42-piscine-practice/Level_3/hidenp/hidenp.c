/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:08:10 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/19 21:03:28 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{

	if (argc == 3)
	{
		while (*argv[2] && *argv[1])
		{
			if (*argv[1] == *argv[2])
				argv[1]++;
			argv[2]++;
		}
		if (*argv[1])
			write(1, "0", 1);
		else
			write(1, "1", 1);
	}
	write(1, "\n", 1);
	return (0);
}
