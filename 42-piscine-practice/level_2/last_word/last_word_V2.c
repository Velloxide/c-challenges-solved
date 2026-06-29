/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word_V2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 22:32:09 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/15 21:04:11 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*last_word;

	str = argv[1];
	last_word = str;
	if (argc == 2 && *str != '\0')
	{
		while (*str)
		{
			if (!is_space(*str) && (str == argv[1] || is_space(*(str - 1))))
				last_word = str;
			str++;
		}
		while (*last_word && !is_space(*last_word))
		{
			write(1, last_word, 1);
			last_word++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
