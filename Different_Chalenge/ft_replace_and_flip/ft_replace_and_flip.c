/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_and_flip.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:06:41 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/11 00:00:54 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_scout(char *str, int *info)
{
	int	i;
	int	nb;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (info[2] == 1 || info[2] == 5)
		{
			if (info[2] == 1)
				info[0] = i;
			else
				info[1] = i;
		}
		if (str[i] != ' ' && str[i] != '\0')
		{
			info[2]++;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}
	info[3] = i;
	i = 1;
	nb = info[2] + 2;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

int	ft_insert_number(char *new_str, int dest_idx, int total_words)
{

}

int	ft_copy_and_flip(char *new_str, int dest_idx, char *str, int src_idx)
{

}

void	ft_builder_copy(char *str, char *arry)
{
	int	i;

	i = 0;
	while (str[i])
	{
		arry[i] = str[i];
		i++;
	}
	arry[i++] = ' ';
	arry[i++] = '\n';
	arry[i] = '\0';
	return ;
}

int	ft_is_match(char *str, int current_idx, int target_idx)
{
	int	i;
	int	j;

	i = current_idx;
	j = target_idx;
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (str[i] != str[j])
			return (0);
		i++;
		j++;
	}
	if (str[j] == ' ')
		return (1);
	return (0);
}

int	ft_copy_second(char *str, int current_idx, char *arry, int j)
{
	while (str[current_idx] != ' ')
	{
		arry[j] = str[current_idx];
		j++;
		current_idx++;
	}
	return (j);
}

void	ft_builder(char *str, char *new_str, int *info)
{
	//$>./a.out "Run   go fast go  and lO jump go  here" | cat -e
	//	     Run   Lo  fast Lo  and 11 go jump Lo   here \n$>
	//   {second_word, sex_word, len_words, len_str}
	//   {      0         1,        2,         3}

	int	i;
	int	j;
	int	word_count;

	i = 0;
	j = 0;
	word_count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			new_str[j] = str[i];
			i++;
			j++;
		}
		else if (str[i] != ' ' && str[i] != '\0')
		{
			word_count++;
			if (word_count == 6)
			{
				j = ft_copy_second(str, info[0], new_str, j);
				while (str[i] != ' ' && str[i] != '\0')
					i++;
			}
			else
			{
				if (ft_is_match(str, i, info[0]))
				{
					j = ft_copy_and_flip();
					while (str[i] != ' ' && str[i] != '\0')
						i++;
				}
				else
				{
					while (str[i] != ' ' && str[i] != '\0')
					{
						new_str[j] = str[i];
						i++;
						j++;
					}
				}
			}
			if (word_count == (info[2] / 2) + 1)
			{
				new_str[j++] = ' ';
				j = ft_insert_number();
			}
		}
	}
	new_str[j++] = ' ';
	new_str[j++] = '\n';
	new_str[j] = '\0';
}

char	*ft_replace_and_flip(char *str)
{
	int	total_len;
	int	len_number;
	int	info[4] = {0};
	char	*arry;

	len_number = ft_scout(str, info);
	if (info[2] < 9 || info[2] % 2 == 0)
	{
		arry = malloc((info[3] + 3) * sizeof(char));
		if (!arry)
			return (NULL);
		ft_builder_copy(str, arry);
		return (arry);
	}
	total_len = info[3] + len_number + 3;
	arry = malloc(total_len * sizeof(char));
	if (!arry)
		return (NULL);
	ft_builder(str, arry, info);
	return (arry);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	char	*arry;
	arry = ft_replace_and_flip(argv[1]);
	//printf("%s\n", arry);
	return (0);
}
