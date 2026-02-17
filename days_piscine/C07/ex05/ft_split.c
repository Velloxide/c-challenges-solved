/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:53:21 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/17 22:09:38 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

static int	check_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset++)
			return (1);
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	len;

	len = 0;
	while (*str)
	{
		while (*str && check_sep(*str, charset))
			str++;
		if (*str && !check_sep(*str, charset))
		{
			while (*str && !check_sep(*str, charset))
				str++;
			len++;
		}
	}
	return (len);
}

static char	*add_word(char **str, char *charset)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while ((*str)[len] && !check_sep((*str)[len], charset))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = (*str)[i];
		i++;
	}
	word[i] = '\0';
	*str += len;
	return (word);
}

static void	*free_all(char **arry, int i)
{
	while (i >= 0)
		free(arry[i--]);
	free(arry);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		words;
	char	**arry;

	words = count_words(str, charset);
	arry = malloc((words + 1) * sizeof(char *));
	if (!arry)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str && check_sep(*str, charset))
			str++;
		arry[i] = add_word(&str, charset);
		if (!arry[i])
			return (free_all(arry, i - 1));
		i++;
	}
	arry[i] = 0;
	return (arry);
}
/*
int	main(int argc, char **argv)
{
	char	**arry;
	int	i;

	if (argc != 3)
		return (1);
	arry = ft_split(argv[1], argv[2]);
	if (!arry)
		return (1);
	i = 0;
	printf("the string: [%s]\n----\nthe charset: [%s]\n----\nMy new **arry:\n",
	argv[1], argv[2]);
	while (arry[i])
	{
		printf("string: %i==> %s \n", (i + 1), arry[i]);
		i++;
	}
	return (0);
}
*/
