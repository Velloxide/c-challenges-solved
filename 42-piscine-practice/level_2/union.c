/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 01:42:15 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/16 03:03:20 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	unsigned char	map[256] = {0};
	char	*ptr;

	if (argc == 3)
	{
		argv++;
		while (*argv)
		{
			ptr = *argv;
			while (*ptr)
			{
				if (!map[(unsigned char) *ptr])
				{
					write(1, ptr, 1);
					map[(unsigned char) *ptr] = 1;
				}
				ptr++;
			}
			argv++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

