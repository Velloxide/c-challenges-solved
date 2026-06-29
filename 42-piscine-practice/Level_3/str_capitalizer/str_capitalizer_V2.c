/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer_V2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 20:17:01 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/22 17:42:24 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isChar(char c)
{
	if ((c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

int	ft_isSpace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc >= 2)
	{
		i = 1;
		while (argv[i])
		{

			j = 0;
			while (argv[i][j])
			{
				if (j == 0 || ft_isSpace(argv[i][j - 1]))
				{
					if (ft_isChar(argv[i][j]) == 1)
						argv[i][j] -= 32;
				}
				else
				{
					if (ft_isChar(argv[i][j]) == 2)
						argv[i][j] += 32;
				}
				write(1, &argv[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
