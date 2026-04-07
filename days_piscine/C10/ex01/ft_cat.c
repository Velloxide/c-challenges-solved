/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:24:37 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/07 21:23:48 by Itachi-Logic     ###   ########.fr       */
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
	argv++;
	while (*argv)
	{
		openf = open(*argv, O_RDONLY);
		if (openf == -1)
		{
			ft_puterror("cat: ");
			ft_puterror(*argv);
			ft_puterror(" : No such file or directory\n");
		}
		else
		{
			ft_display_content(openf);
			close(openf);
		}
		argv++;
	}
	return (0);
}
