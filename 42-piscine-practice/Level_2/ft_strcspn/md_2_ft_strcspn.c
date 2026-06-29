/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_2_ft_strcspn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:39:53 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:39:55 by Itachi-Logic     ###   ########.fr       */
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
	if (*str == c)
		return (1);
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(reject, s[i]))
			return (i);
		else
			i++;
	}
	return (i);
}
/*
int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	printf("%zu\n", ft_strcspn(av[1], av[2]));
}
*/
