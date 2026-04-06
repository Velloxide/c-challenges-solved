/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:24:37 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/06 21:58:40 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft.h"

int	main(int argc, char **argv)
{
	int	openf;

	if (argc < 2)
	{
		ft_puterror("File name missing.\n");
		return (1);
	}
	openf = open(argv[1], O_RDONLY);
	if (openf == -1)
	{
		int i;

		i = 1;
		while (argv[i])
		{
			ft_puterror("cat: ");
			ft_puterror(argv[i]);
			ft_puterror(" : No such file or directory\n");
			i++;
		}
		return (1);
	}
	ft_display_content(openf);
	close(openf);
	return (0);
}
