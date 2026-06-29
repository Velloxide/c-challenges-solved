/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:37:23 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/24 16:47:18 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_skipWhile(char *src, int i, int loop)
{
	while (loop > 0)
	{
		i++;
		if (src[i] == '[')
			loop++;
		if (src[i] == ']')
			loop--;
	}
	return (i);
}

int	ft_doWhile(char *src, int i, int loop)
{
	while (loop > 0)
	{
		i--;
		if (src[i] == ']')
			loop++;
		if (src[i] == '[')
			loop--;
	}
	return (i);
}

void	ft_brainfuck(char *src)
{
	char	*dest;
	int	i;
	int	j;

	dest = malloc((2048) * sizeof(char));
	if (!dest)
		return ;
	
	j = 0;
	while (j < 2048)
		dest[j++] = 0;
	j = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] == '>')
			j++;
		else if (src[i] == '<')
			j--;
		else if (src[i] == '+')
			dest[j] += 1;
		else if (src[i] == '-')
			dest[j] -= 1;
		else if (src[i] == '.')
			write(1, &dest[j], 1);
		else if (src[i] == '[' && dest[j] == 0)
			i = ft_skipWhile(src, i, 1);
		else if (src[i] == ']' && dest[j] != 0)
			i = ft_doWhile(src, i, 1);
		i++;
	}
	free(dest);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		ft_brainfuck(av[1]);
	return (0);
}
