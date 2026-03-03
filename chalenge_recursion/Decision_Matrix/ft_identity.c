/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:27:47 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/02 22:19:58 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valide(char *str, char *arry)
{
	int		i;
	int		j;
	int		count;
	char	target;

	i = 0;
	while (str[i])
	{
		target = str[i];
		count = arry[i++] - 48;
		j = 0;
		while (arry[j])
		{
			if (target == arry[j++])
				count--;
		}
		if (count != 0)
			return (0);
	}
	return (1);
}

int	ft_stop(char *s, int len)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while(s[i])
	{
		sum = sum + (s[i] - 48);
		i++;
	}
	if(sum == len)
		return (1);
	return 0;
}

void	check_print(char *arry, char *str, int len, int current_index)
{
	arry[current_index] = '\0';
	if (ft_stop(arry, len))
	{
		if (is_valide(str, arry))
		{
			write(1, arry, len);
			write(1, "\n", 1);
		}
	}
}

void	solve_helper(char *str, char *arry, int current_index, int count)
{
	char	digits;
	int		len;

	len = arry[11];
	if (current_index == len)
	{
		check_print(arry, str, len, current_index);
		return ;
	}
	if (count > len)
		return ;
	digits = '0';
	while (digits <= (len + '0'))
	{
		arry[current_index] = digits;
		solve_helper(str, arry, current_index + 1, count + (digits - '0'));
		digits++;
	}
}

void	ft_identity(char *str)
{
	int		len;
	char	arry[12];

	len = 0;
	while (str[len])
		len++;
	if (len > 10)
		return ;
	arry[11] = len;
	solve_helper(str, arry, 0, 0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	ft_identity(argv[1]);
	return (0);
}
