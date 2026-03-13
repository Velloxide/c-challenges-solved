/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compress_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 01:17:56 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/13 01:25:44 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_len_number(int nb)
{
	int	i;

	i = 1;
	while (nb > 9)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_putnbr(char *arry, int j, int size_c)
{
	if (size_c > 9)
	{
		j = ft_putnbr(arry, j, size_c / 10);
	}
	arry[j] = (size_c % 10) + '0';
	return (j + 1);
}

void	ft_solve_help(char *str, char *arry)
{
	int	i;
	int	size_c;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		arry[j] = str[i];
		size_c = 0;
		while (str[i] == arry[j])
		{
			i++;
			size_c++;
		}
		j++;
		j = ft_putnbr(arry, j, size_c);
	}
	arry[j] = '\0';
	return ;
}

char	*ft_compress_str(char *str)
{
	//❯ ./a.out    "aabbcaccc"  | cat -e
	//              a  b c   $
	int	i;
	int	size_c;
	int	len_new_str;
	char	c;
	char	*arry;

	i = 0;
	len_new_str = 0;
	while (str[i])
	{
		c = str[i];
		size_c = 0;
		while (str[i] == c)
		{
			i++;
			size_c++;
		}
		len_new_str += ft_len_number(size_c) + 1;
	}
	arry = malloc((len_new_str + 1) * sizeof(char));
	if (!arry)
		return (NULL);
	ft_solve_help(str, arry);
	printf("%s\n", arry);
	return (arry);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	ft_compress_str(argv[1]);
	return (0);
}
