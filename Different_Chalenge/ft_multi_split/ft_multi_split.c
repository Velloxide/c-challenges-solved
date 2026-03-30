/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:01:15 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/29 11:50:51 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_same(char *str, char *del)
{
	int	i;

	i = 0;
	while (del[i] && str[i] && str[i] == del[i])
		i++;
	if (!del[i])
		return (i);
	return (0);
}

int	ft_get_sep_len(char *str, char **del)
{
	int	j;
	int	len_del;

	j = 0;
	while (del[j])
	{
		len_del = ft_is_same(str, del[j]);
		if (len_del > 0)
			return (len_del);
		j++;
	}
	return (0);

}

int	ft_len_arrys(char *str, char **del)
{
	int	i;
	int	in_word;
	int	len_del;
	int	count;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		len_del = ft_get_sep_len((str + i), del);
		if (len_del > 0)
		{
			i += len_del;
			in_word = 0;
		}
		else
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
			i++;
		}
	}
	return (count);
}

int	ft_word_len(char *str, char **del)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_get_sep_len((str + i), del) > 0)
			return (i);
		i++;
	}
	return (i);
}

void	ft_strncpy(char *src, char *dest, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_free_all(char **arrys, int i)
{
	while (i >= 0)
	{
		free(arrys[i]);
		i--;
	}
	free(arrys);
}

char	**ft_multi_split(char *str, char **delimiters)
{
	char	**arrys;
	int		len_words;
	int		len;
	int		opt;
	int		i;
	int		j;

	len_words = ft_len_arrys(str, delimiters);
	arrys = malloc((len_words + 1) * sizeof(char *));
	if (!arrys)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		opt = ft_get_sep_len((str + i), delimiters);
		if (opt > 0)
			i += opt;
		else
		{
			len = ft_word_len((str + i), delimiters);
			arrys[j] = malloc((len + 1) * sizeof(char));
			if (!arrys[j])
			{
				ft_free_all(arrys, --j);
				return (NULL);
			}
			ft_strncpy((str + i), arrys[j], len);
			i += len;
			j++;
		}
	}
	arrys[len_words] = NULL;
	return (arrys);
}


int	main(void)
{
	char	**newstr;
	char	*str = "hello world, this is multi.split! ex..._-for-said.with.hamzza";
	char	*del[] = {" ", ",", "!", "-", "_", NULL};
	int	i;

	newstr = ft_multi_split(str, del);
	if (!newstr)
		return (0);
	i = 0;
	while(newstr[i])
		printf("%s\n", newstr[i++]);
	ft_free_all(newstr, --i);
}
