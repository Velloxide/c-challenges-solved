/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch_V2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 02:48:47 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/16 20:04:08 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*push;

	if (argc == 3)
	{
		push = argv[1];
		while (*argv[2])
			if (*push == *(argv[2]++))
				push++;
		if (!*push)
			write(1, argv[1], (push - argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
