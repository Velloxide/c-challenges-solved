/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:34:59 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:35:01 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int	i;
	char	*newstr;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	newstr = (char *)malloc((i + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("please enter just 1 string:\n");
		return (1);
	}
	printf("this is original string: %s\n", av[1]);
	printf("this is new string: %s\n", ft_strdup(av[1]));
}
*/
