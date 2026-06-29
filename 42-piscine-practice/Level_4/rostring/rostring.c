/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 01:03:54 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/14 17:41:11 by Itachi-Logic     ###   ########.fr       */
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
	char	*ptr;
	char	*began_first_word;
	int	len_first;

	if (argc == 2)
	{
		ptr = argv[1];
		while (*ptr && __isSpase(*ptr))
			ptr++;
		began_first_word = ptr;
		while (*ptr && !__isSpase(*ptr))
			ptr++;
		len_first = (int)(ptr - began_first_word);
		while (*ptr)
		{
			while (*ptr && __isSpase(*ptr))
				ptr++;
			if (*ptr)
			{
				while (*ptr && !__isSpase(*ptr))
					write(1, ptr++, 1);
				write(1, " ", 1);
			}
		}
		write(1, began_first_word, (len_first));
	}
	write(1, "\n", 1);
	return (0);
}
