/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 23:14:25 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/02/28 00:57:04 by Itachi-Logic     ###   ########.fr       */
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

void	ft_sort_array(char **word, int size)
{
	int		k;
	int		l;
	char	*tmp;

	k = 0;
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
