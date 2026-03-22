/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dynamic_caesar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 01:32:56 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/22 10:47:09 by Itachi-Logic     ###   ########.fr       */
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
	while (str[i])
	{
		arry[i] = (str[i] - 'a' + shift) % 26 + 'a';
		i++;
	}
	return (arry);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	int	nb;
	char	*str;

	nb = atoi(argv[2]);
	str = ft_dynamic_caesar(argv[1], nb);
	printf("%s\n", str);
	return (0);
}
