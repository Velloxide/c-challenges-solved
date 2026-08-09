/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:26:07 by saboutay          #+#    #+#             */
/*   Updated: 2026/07/30 19:59:40 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
$> ./brackets '(johndoe)' | cat -e
OK$
$> ./brackets '([)]' | cat -e
Error$
$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
OK$
OK$
$> ./brackets | cat -e
$
$>
*/

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
			return (*(buf + 3));
		buf++;
	}
	return (0);
}

int	ft_brackets(char *code)
{
	char	stack[2000];
	int	i;
	int	top;

	top = -1;
	i = 0;
	while (code[i])
	{
		if (ft_is_open(code[i]))
		{
			top++;
			stack[top] = code[i];
		}
		if (ft_is_close(code[i]))
		{
			if (top == -1)
				return (0);
			if (stack[top] == get_close(code[i]))
				top--;
			else
				return (0);
		}
		i++;
	}
	if (top == -1)
		return (1);
	return (0);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	nb;

	if (argc != 2)
		return (0);
	nb = ft_brackets(argv[1]);
	if (nb)
		printf("Ok");
	else
		printf("error");
	return (0);
}
