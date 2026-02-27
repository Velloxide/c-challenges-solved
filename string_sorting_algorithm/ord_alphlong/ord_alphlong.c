/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:45:12 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/27 01:15:05 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcasecmp(char *s1, char *s2)
{
	int	i = 0;
	char	c1, c2;
	
	while (s1[i] || s2[i])
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 >= 'A' && c1 <= 'Z')
			c1 += 32;
		if (c2 >= 'A' && c2 <= 'Z')
			c2 += 32;
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}

int	ft_len_words(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}
	return (count);
}

void	ft_sort_array(char **word, int size)
{
	int		k = 0;
	int		l;
	char	*tmp;
	while (k < size - 1)
	{
		l = k + 1;
		while (l < size)
		{
			if (ft_strlen(word[k]) > ft_strlen(word[l]))
			{
				tmp = word[k];
				word[k] = word[l];
				word[l] = tmp;
			}
			else if (ft_strlen(word[k]) == ft_strlen(word[l]))
			{
				if (ft_strcasecmp(word[k], word[l]) > 0)
				{
					tmp = word[k];
					word[k] = word[l];
					word[l] = tmp;
				}
			}
			l++;
		}
		k++;
	}
}

void	ft_print_array(char **word, int size)
{
	int	k = 0;
	while (k < size)
	{
		printf("%s", word[k]);
		if (k + 1 < size)
		{
			if (ft_strlen(word[k]) == ft_strlen(word[k + 1]))
				printf(" ");
			else
				printf("\n");
		}
		k++;
	}
	printf("\n");
}

void	ft_ord_alphlong(char *str)
{
	char	**word;
	int	len_wods;
	int	i;
	int	j;

	len_wods = ft_len_words(str);
	if (len_wods == 0)
		return ;
	word = malloc(sizeof(char *) * (len_wods + 1));
	if (!word)
		return ;
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			str[i++] = '\0';
		if (str[i] != '\0')
		{
			word[j] = &str[i];
			while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
				i++;
			j++;
		}
	}
	ft_sort_array(word, j);
	ft_print_array(word, j);
	free(word);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	ft_ord_alphlong(argv[1]);
	return (0);
}
