/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:36:13 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:36:16 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_inter(char *str1, char *str2)
{
	int	ascii[256] = {0};
	int	i;
	int	val_index;

	i = 0;
	while (str2[i])
	{
		val_index = (int)str2[i];
		if (ascii[val_index] == 0)
			ascii[val_index] = 1;
		i++;
	}
	i = 0;
	while (str1[i])
	{
		val_index = (int)str1[i];
		if (ascii[val_index] == 1)
		{
			ascii[val_index] = 2;
			write(1, &str1[i], 1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
