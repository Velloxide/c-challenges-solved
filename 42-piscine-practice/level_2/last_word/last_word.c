/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:32:09 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/15 20:38:31 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int	main(int argc, char *argv[])
{
	char	*start;
	char	*str;

	str = argv[1];
	if (argc == 2 && *str != '\0')
	{
		start = str;
		while (*str)
			str++;
		str--;
		while (str >= start && is_space(*str))
			str--;
		while (str >= start && !is_space(*str))
			str--;
		str++;
		while (*str && !is_space(*str))
		{
			write(1, str, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
