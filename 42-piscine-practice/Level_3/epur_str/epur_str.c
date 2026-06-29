/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 22:15:06 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/17 12:50:28 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_spase(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		while (*argv[1] && ft_is_spase(*argv[1]))
			argv[1]++;
		while (*argv[1])
		{
			while (*argv[1] && ft_is_spase(*argv[1]))
			{
				if ((*(argv[1] + 1) != '\0') && !ft_is_spase(*(argv[1] + 1)))
					write(1, " ", 1);
				argv[1]++;
			}
			while (*argv[1] && !ft_is_spase(*argv[1]))
			{
				write(1, argv[1], 1);
				argv[1]++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
