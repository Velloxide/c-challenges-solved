/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 20:15:16 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/22 16:07:45 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isChar(char c, int *stite)
{
	if (c >= 'a' && c <= 'z')
	{
		*stite = 2;
		return (1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		*stite = 1;
		return (1);
	}
	*stite = 0;
	return (0);
}

int	ft_isEndWord(char c)
{
	if (c == '\0' || c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	main(int argc, char *str[])
{
	int	i;
	int	stite;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while(str[i])
	{
		stite = 0;
		while (*str[i])
		{
			if (ft_isChar(*str[i], &stite) && !ft_isEndWord(*(str[i] + 1)))
			{
				if (stite == 1)
					*str[i] += 32;
			}
			else if (ft_isChar(*str[i], &stite) && ft_isEndWord(*(str[i] + 1)))
			{
				if (stite == 2)
					*str[i] -= 32;
			}
			write(1, str[i], 1);
			str[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
