/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:45:12 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/28 23:39:42 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ord_tools.h"

int	ft_len_words(char *str)
{
	int	count;
	int	i;

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

void	ft_ord_alphlong(char *str)
{
	char	**word;
	int		len_wods;
	int		j;

	len_wods = ft_len_words(str);
	if (len_wods == 0)
		return ;
	word = malloc(sizeof(char *) * (len_wods + 1));
	if (!word)
		return ;
	j = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			*str++ = '\0';
		if (*str != '\0')
		{
			word[j] = &(*str);
			while (*str != '\0' && *str != ' ' && *str != '\t')
				str++;
			j++;
		}
	}
	word[j] = NULL;
	ft_sort_array(word, j);
	ft_print_array(word, j);
	free(word);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	ft_ord_alphlong(argv[1]);
	return (0);
}
