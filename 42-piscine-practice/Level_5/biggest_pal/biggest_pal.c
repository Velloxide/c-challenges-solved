/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:03:18 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/23 20:36:38 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_cheakbigg(char *str, int i, int j, int *old_len)
{
	int	len;

	len = j - i;
	if (*old_len > len)
		return (0);
	while (i < j)
	{
		if (str[i] != str[j])
			return (0);
		i++;
		j--;
	}
	*old_len = len;
	return (1);
}

void	biggest_pal(char *str)
{
	int	i;
	int	j;
	int	start;
	int	len;

	i = 0;
	len = 0;
	start = 0;
	while (str[i])
	{
		j = i;
		while (str[j])
		{
			if (str[i] == str[j])
			{
				if (ft_cheakbigg(str, i, j, &len))
					start = i;
			}
			j++;
		}
		i++;
	}
	write(1, (str + start), (len + 1));
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		biggest_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}
