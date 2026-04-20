/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 10:09:54 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/20 21:22:00 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_tail.h"

int	main(int argc, char *argv[])
{
	int	nb;
	int	file_index;
	int	total_files;
	int	file_d;
	
	nb = 0;
	file_index = check_formula(argc, argv, &nb);
	if (file_index == -1)
		return (1);
	total_files = argc - file_index;
	if (total_files == 0)
	{
		ft_display_tail(0, nb);
		return (0);
	}
	while (file_index < argc)
	{
		if (total_files > 1)
			ft_print_header(argv[file_index], file_index, argc - total_files);
		file_d = open(argv[file_index], O_RDONLY);
		ft_display_tail(file_d, nb);
		close(file_d);
		file_index++;
	}
	return (0);
}
