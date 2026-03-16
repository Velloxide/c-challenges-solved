/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zigzag_with_string_words_V2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 00:49:03 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/16 01:51:22 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

char	*ft_evenodd(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			j ^= j;
		else
		{
			if (j == 0)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] &= ~32;
			}
			else
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] |= 32;
			}
			j ^= 1;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str[] = "Weird string case";
	printf("%s\n", ft_evenodd(str));
	return (0);
}

