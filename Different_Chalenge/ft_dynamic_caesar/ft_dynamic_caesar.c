/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamic_caesar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 01:32:56 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/22 11:07:49 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_dynamic_caesar(char *str, int shift)
{
	int	i;
	char	*arry;

	i = 0;
	while (str[i])
		i++;
	arry = malloc((i + 1) * sizeof(char));
	if (!arry)
		return (NULL);
	arry[i] = '\0';
	i = 0;
	shift = (shift % 26 + 26) % 26;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			arry[i] = (str[i] - 'a' + shift) % 26 + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			arry[i] = (str[i] - 'A' + shift) % 26 + 'A';
		else
			arry[i] = str[i];
		i++;
	}
	return (arry);
}

int	main(int argc, char *argv[])
{
	int		nb;
	char	*str;

	if (argc != 3)
		return (0);
	nb = atoi(argv[2]);
	str = ft_dynamic_caesar(argv[1], nb);
	printf("%s\n", str);
	return (0);
}
