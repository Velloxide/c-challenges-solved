/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:31:22 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/10 23:37:49 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest + i);
}

static int	ft_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	if (size <= 0)
		return (0);
	total_len = 0;
	i = 0;
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	total_len += ((size - 1) * ft_strlen(sep));
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*dest;
	char	*ptr;

	dest = (char *) malloc(ft_total_len(size, strs, sep) * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	if (size == 0)
	{
		*dest = '\0';
		return (dest);
	}
	ptr = dest;
	i = 0;
	while (i < size)
	{
		dest = ft_strcpy(dest, strs[i]);
		if (i++ < size - 1)
			dest = ft_strcpy(dest, sep);
	}
	*dest = '\0';
	return (ptr);
}
/*
int	main(void)
{
	char	*dest;
	char	*strs[9] = {"Hello", "said"};

	dest = ft_strjoin(2 , strs, "-");
	printf("this is strs: %s\n", dest);
	free(dest);
	return (0);
}
*/
