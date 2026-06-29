/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 22:21:46 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/10 21:28:40 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	isSpace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	ft_lenWords(char *str)
{
	int	i;
	char	*start;

	i = 0;
	start = str;
	while (*str)
	{
		if (!isSpace(*str) && (str == start || isSpace(*(str - 1))))
			i++;
		str++;
	}
	return (i);
}

char	**ft_fullArry(char *str, char **arry)
{
	int	i;
	int	j;
	char	*end_word;

	while (*str && isSpace(*str))
		str++;
	i = 0;
	while (*str)
	{
		end_word = str;
		while (*end_word && !isSpace(*end_word))
			end_word++;
		arry[i] = malloc((end_word - str + 1) * sizeof(char));
		if (!arry[i])
			return (NULL);
		j = 0;
		while (str < end_word)
			arry[i][j++] = *str++;
		arry[i++][j] = '\0';
		while (*str && isSpace(*str))
			str++;
	}
	return (arry);
}

char    **ft_split(char *str)
{
	char	**arry;
	int	lenWords;

	lenWords = ft_lenWords(str);
	arry = malloc((lenWords + 1) * sizeof(char *));
	if (!arry)
		return(NULL);
	arry[lenWords] = NULL;
	return (ft_fullArry(str, arry));
}
/*
void	freeAll(char **arry, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(arry[j]);
		j++;
	}
	free(arry);
}

int	main(int argc, char *argv[])
{
	char	**arry;
	int	i;

	arry = ft_split(argv[1]);

	i = 0;
	while (arry[i])
	{
		printf("%s\n", arry[i]);
		i++;
	}
	freeAll(arry, i);
	return (0);
}
*/
