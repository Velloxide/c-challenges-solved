/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:14:25 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/28 23:23:15 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_tools.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_swap(char **word, int k, int l)
{
	char	*tmp;

	tmp = word[k];
	word[k] = word[l];
	word[l] = tmp;
}

void	ft_sort_array(char **word, int size)
{
	int	k;
	int	l;
	int	len_k;
	int	len_l;

	k = 0;
	while (k < size - 1)
	{
		l = k + 1;
		while (l < size)
		{
			len_k = ft_strlen(word[k]);
			len_l = ft_strlen(word[l]);
			if (len_k > len_l)
				ft_swap(word, k, l);
			else if (len_k == len_l)
			{
				if (ft_strcasecmp(word[k], word[l]) > 0)
					ft_swap(word, k, l);
			}
			l++;
		}
		k++;
	}
}
