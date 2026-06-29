/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 21:54:03 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/14 19:29:10 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	__isSpase(char c)
{
	if (c == ' ' || c == '\t' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	char	*ptr;

	if (argc == 2)
	{
		ptr = argv[1];
		i = 0;
		while (ptr[i])
			i++;
		i -= 1;
		while (i >= 0)
		{
			j = i;
			while (i >= 0 && !__isSpase(ptr[i]))
				i--;
			write(1, (ptr + i + 1), (j - i));
			if (i >= 0)
				write (1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
