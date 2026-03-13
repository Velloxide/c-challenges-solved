/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_and_flip.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:06:41 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/13 23:13:26 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	ft_scout(char *str, int *info)
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
	info[3] = i + 1;
	i = 1;
	nb = info[2] + 2;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	ft_insert_number(char *new_str, int dest_idx, int total_words)
{
	if (total_words <= 9)
	{
		new_str[dest_idx] = (total_words % 10) + '0';
		return (dest_idx + 1);
	}
	if (total_words > 9)
		dest_idx = ft_insert_number(new_str, dest_idx, total_words / 10);
	new_str[dest_idx] = (total_words % 10) + '0';
	return (dest_idx + 1);
}

static int	ft_copy_and_flip(char *new_str, int dest_idx, char *str, int src_idx)
{
	while (str[src_idx] != ' ' && str[src_idx] != '\0')
	{
		if (str[src_idx] >= 'a' && str[src_idx] <= 'z')
			new_str[dest_idx] = str[src_idx] - 32;
		else if (str[src_idx] >= 'A' && str[src_idx] <= 'Z')
			new_str[dest_idx] = str[src_idx] + 32;
		else
			new_str[dest_idx] = str[src_idx];
		src_idx++;
		dest_idx++;
	}
	return (dest_idx);
}

static void	ft_builder_copy(char *str, char *arry)
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

static int	ft_is_match(char *str, int current_idx, int target_idx)
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

static int	ft_copy_second(char *str, int current_idx, char *arry, int j)
{
	while (str[current_idx] != ' ' && str[current_idx] != '\0')
	{
		arry[j] = str[current_idx];
		j++;
		current_idx++;
	}
	return (j);
}

static void	ft_add_suffix(char *new_str, int j)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		new_str[j++] = " \\n\n\0"[i];
		i++;
	}
}

static void	ft_builder(char *str, char *new_str, int *info)
{
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
					j = ft_copy_and_flip(new_str, j, str, info[1]);
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
				j = ft_insert_number(new_str, j, info[2] + 2);
			}
		}
	}
	ft_add_suffix(new_str, j);
}

static int	ft_calculate_memory(char *str, int *info)
{
	int	len2;
	int	len6;
	int	count2;
	int	i;
	int	total_len;

	len2 = 0;
	while (str[info[0] + len2] && str[info[0] + len2] != ' ')
		len2++;
	len6 = 0;
	while (str[info[1] + len6] && str[info[1] + len6] != ' ')
		len6++;
	i = 0;
	count2 = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
		{
			if (ft_is_match(str, i, info[0]))
				count2++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	total_len = info[3];
	total_len += (count2 * len6) - (count2 * len2);
	total_len += (len2 - len6);
	return (total_len);
}

char	*ft_replace_and_flip(char *str)
{
	int	total_len;
	int	len_number;
	int	info[4] = {0};
	char	*arry;
	//       arry =   {second_word, sex_word, size_words, len_str}
	//       arry =   {      0         1,         2,         3}
	len_number = ft_scout(str, info);
	if (info[2] < 9 || info[2] % 2 == 0)
	{
		arry = malloc((info[3] + 2) * sizeof(char));
		if (!arry)
			return (NULL);
		ft_builder_copy(str, arry);
		return (arry);
	}
	total_len = ft_calculate_memory(str, info) + len_number + 5;
	arry = malloc(total_len * sizeof(char));
	if (!arry)
		return (NULL);
	ft_builder(str, arry, info);
	return (arry);
}

int	main(int argc, char *argv[])
{
	char	*arry;

	if (argc != 2)
		return (0);
	arry = ft_replace_and_flip(argv[1]);
	printf("%s", arry);
	free(arry);
	return (0);
}
