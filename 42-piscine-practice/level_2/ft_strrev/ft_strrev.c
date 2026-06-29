/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:35:15 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:35:18 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char    *ft_strrev(char *str)
{
	int	f;
	int	l;
	char	temp;
	if (str == NULL)
		return (str);
	l = 0;
	while (str[l])
		l++;
	l--;
	f = 0;
	while (l >= f)
	{
		temp = str[f];
		str[f] = str[l];
		str[l] = temp;
		l--;
		f++;
	}
	return (str);
}
/*
int	main(int ac, char *av[])
{
	char	*str;

	if (ac != 2)
	{
		printf("please enter 1 string you whant revarse!\n");
		return (1);
	}
	printf("Before revarse: %s\n", av[1]);
	str = ft_strrev(av[1]);
	printf("After revarse: %s\n", str);
}
*/
