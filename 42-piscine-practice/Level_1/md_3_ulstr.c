/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_3_ulstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:34:03 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:34:05 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int   main(int ac, char **av)
{
	int	i;
	int	j;
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				j = str[i];
				j -= 32;
				write(1, &j, 1);
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				j = str[i];
				j += 32;
				write(1, &j, 1);
			}
			else
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
