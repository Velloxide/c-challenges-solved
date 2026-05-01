/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 10:09:54 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/01 19:46:53 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_tail.h"

int	main(int argc, char *argv[])
{
	int	nb;
	int	mode;
	int	file_index;
	int	total_files;
	int	file_d;
	
	nb = 0;
	mode = 0;
	file_index = check_formula(argc, argv, &nb, &mode);
	if (file_index == -1)
		return (1);
	total_files = argc - file_index;
	if (total_files == 0)
	{
		if (mode == 1)
			ft_display_tail(0, nb);
		else
			ft_display_lines(0, nb);
		return (0);
	}
	while (file_index < argc)
	{
		file_d = open(argv[file_index], O_RDONLY);
		if (file_d == -1)
			ft_display_error(argv[0], argv[file_index]);
		else
		{
			if (total_files > 1)
				ft_print_header(argv[file_index], file_index, argc - total_files);
			if (mode == 1)
				ft_display_tail(file_d, nb);
			else
				ft_display_lines(file_d, nb);
			close(file_d);
		}
		file_index++;
	}
	return (0);
}
