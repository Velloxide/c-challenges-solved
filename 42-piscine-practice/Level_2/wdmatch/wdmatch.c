/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 02:48:47 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/27 21:23:03 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
//quarante deux$
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	switsh;
	char	*ptr;

	if (argc == 3)
	{
		switsh = 1;
		ptr = argv[1];
		while (*argv[1] && switsh)
		{
			switsh = 0;
			while (*argv[2] && !switsh)
			{
				if (*argv[1] == *argv[2])
					switsh = 1;
				argv[2]++;
			}
			if (!switsh)
			{
				write(1, "\n", 1);
				return (0);
			}
			argv[1]++;
		}
		if (!*argv[1])
		{
			while (*ptr)
				write(1, ptr++, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
