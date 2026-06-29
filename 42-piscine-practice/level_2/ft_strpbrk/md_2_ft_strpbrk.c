/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_2_ft_strpbrk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:40:11 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:40:44 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (*s1)
	{
		if (ft_strchr(s2, *s1))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
/*
int	main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("please enter 2 string!\n");
		return (1);
	}
	printf("this is s1: %s\nthis is s2: %s\n-------------\n", av[1], av[2]);
	printf("this is result: %s\n", ft_strpbrk(av[1], av[2]));
}
*/
