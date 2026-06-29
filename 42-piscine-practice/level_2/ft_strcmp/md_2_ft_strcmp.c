/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_2_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:39:29 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:39:31 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i]) && (s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
/*
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%i\n", ft_strcmp(av[1], av[2]));
	}
	return (0);
}
*/
