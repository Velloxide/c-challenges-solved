/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:35:49 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:35:52 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

size_t	ft_strchr(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t  ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
	
		if (ft_strchr(accept, s[i]) == 1)
			i++;
		else
			return (i);
	}
	return (i);
}
/*
int	main(int ac, char *av[])
{
	if (ac != 3)
		return (1);
	printf("number is: %zu\n", ft_strspn(av[1], av[2]));
}
*/
