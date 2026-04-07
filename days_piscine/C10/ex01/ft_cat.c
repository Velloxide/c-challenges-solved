/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:24:37 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/07 23:08:14 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft.h"

int	main(int argc, char **argv)
{
	int	openf;
	int	i;

	if (argc < 2)
	{
		ft_display_content(0);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		openf = open(argv[i], O_RDONLY);
		if (openf == -1)
			ft_err_handling(argv, i);
		else
		{
			if (ft_display_content(openf) == -1)
				ft_err_handling(argv, i);
			close(openf);
		}
		i++;
	}
	return (0);
}
