/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 23:36:32 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/31 22:23:46 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], sep))
		{
			while (str[i] && ft_is_sep(str[i], sep))
				i++;
		}
		else {
			count++;
			while (str[i] && !ft_is_sep(str[i], sep))
				i++;
		}
	}
	return (count);
}

int	ft_len_put(char *str, char *sep, char *res, int put_or_no)
{
	int	i;

	i = 0;
	if (put_or_no)
	{
		while (str[i] && !ft_is_sep(str[i], sep))
		{
			res[i] = str[i];
			i++;
		}
		res[i] = '\0';
	}
	else
	{
		while (str[i] && !ft_is_sep(str[i], sep))
			i++;
	}
	return (i);
}

void	ft_free_all(char **res, int j)
{
	while (j >= 0)
		free(res[j--]);
	free(res);
}

int	ft_putres(char **res, char *str, char *sep, int len_res)
{
	int	j;
	int	len_word;

	j = 0;
	while (*str)
	{
		if (ft_is_sep(*str, sep))
		{
			while (*str && ft_is_sep(*str, sep))
				str++;
		}
		else {
			len_word = 1 + ft_len_put(str, sep, res[j], 0);
			res[j] = malloc(len_word * sizeof(char));
			if (!res[j])
			{
				ft_free_all(res, (j - 1));
				return (1);
			}
			str += ft_len_put(str, sep, res[j++], 1);
		}
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	int	count_words;
	int	i;
	char	**res;
	
	count_words = 1 + ft_count_words(str, charset);
	res = malloc(count_words * sizeof(char *));
	if (!res)
		return (NULL);
	res[count_words - 1] = NULL;
	i = ft_putres(res, str, charset, count_words);
	if (i)
		return (NULL);
	return (res);
}

int	main(int argc, char **argv)
{
	char	**res;
	int	i;

	if (argc != 3)
		return (0);
	res = ft_split(argv[1], argv[2]);
	if (!res)
		return (0);
	i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	ft_free_all(res, i);
	return (0);
}
