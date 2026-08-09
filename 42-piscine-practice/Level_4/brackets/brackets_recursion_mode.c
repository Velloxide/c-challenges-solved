/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets_recursion_mode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:02:08 by saboutay          #+#    #+#             */
/*   Updated: 2026/07/30 21:51:37 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_open(char c)
{
	char	*buf;

	buf = "([{";
	while (*buf)
		if (c == *buf++)
			return (1);
	return (0);
}

int	ft_is_close(char c)
{
	char	*buf;

	buf = ")]}";
	while (*buf)
		if (c == *buf++)
			return (1);
	return (0);
}

char	get_close(char c)
{
	char	*buf;

	buf = ")]}([{";
	while (*buf)
	{
		if (*buf == c)
			return (*(buf - 3));
		buf++;
	}
	return (0);
}

char	*ft_recursion(char *code, char expected_close)
{
	while (*code)
	{
		if (ft_is_open(*code))
		{
			code = ft_recursion(code + 1, get_close(*code));
			if (!code)
				return (NULL);
		}
		else if (ft_is_close(*code))
		{
			if (*code == expected_close)
				return (code);
			else
				return (NULL);
		}
		code++;
	}
	if (!*code)
	{
		if (expected_close != 0)
			return (NULL);
	}
	return (code);
}

char	*ft_brackets(char *code)
{
	char	*res;

	res = ft_recursion(code, 0);
	return (res);
}

int	main(int argc, char *argv[])
{
	char	*res;
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		res = ft_brackets(argv[i]);
		if (res)
			printf("OK\n");
		else
			printf("Error\n");
		i++;
	}
	return (0);
}
