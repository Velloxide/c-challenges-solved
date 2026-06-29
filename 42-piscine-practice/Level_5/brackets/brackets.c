/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:58:49 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/21 14:55:15 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isBracketOpen(char c)
{
	char	*brack;

	brack = "({[";
	while (*brack)
	{
		if (c == *brack)
			return (1);
		brack++;
	}
	return (0);
}

int	isBracketCloss(char c)
{
	char	*brack;

	brack = ")}]";
	while (*brack)
	{
		if (c == *brack)
			return (1);
		brack++;
	}
	return (0);
}

char	get_close(char c)
{
	char	*brack;

	brack = "(){}[]";
	while (*brack)
		if (*brack++ == c)
			return (*brack);
	return ('\0');
}

int	ft_brackets(char **str, char expected_close)
{
	char	new_close;

	while (**str)
	{
		if (isBracketOpen(**str))
		{
			new_close = get_close(**str);
			(*str)++;
			if (!ft_brackets(str, new_close))
				return (0);
		}
		else if (isBracketCloss(**str))
		{
			if (**str != expected_close)
				return (0);
			(*str)++;
			return (1);
		}
		else
			(*str)++;
	}
	if (expected_close == '\0')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (ft_brackets(&argv[i], '\0'))
			write(1, "OK", 2);
		else
			write(1, "Error", 3);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
