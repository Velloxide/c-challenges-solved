/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_and_flip.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:06:41 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/09 01:34:57 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;
	
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_len_word(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		while (*str == ' ')
        		str++;
		if (*str != '\0')
		{
			len++;
			while (*str && *str != ' ')
				str++;
		}
	}
	return (len);
}

int	ft_len_number(int nb)
{
	int	i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_find(char *str, int index)
{
	int	from;
	int	to;
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != ' ')
			i++;
		if (str[i] != '\0')
		{
			count++;
			if (count == index)
				from = i;
			while (str[i] && str[i] != ' ')
				i++;
			if (count == index)
				to = i;
		}
	}
	arry = malloc(sizeof(char) * .....);

}

void	ft_solve_helper(char *str, char *arry)
{
	// "Run   go   fast go  and lO jump go   here"
	// "Run   Lo   fast Lo  and 11 go jump Lo   here \n"
	char	*i_one;
	char	*i_five;

	i_one = ft_find(str, 1);
	i_five = ft_find(str, 5)

	
}

char    *ft_replace_and_flip(char *str)
{
	int	len;
	int	len_word;
	int	len_number;
	int	total_len;
	char	*arry;

	len_word = ft_len_word(str);
	len = ft_strlen(str);
	len_number = ft_len_number(len_word);
	total_len = len + len_number + 3;
	arry = malloc(total_len * sizeof(char));
	if (!arry)
		return (NULL);
	arry[total_len - 1] = '\0';
	ft_solve_helper(str, arry);
	return (arry);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	ft_replace_and_flip(argv[1]);
	return (0);
}
