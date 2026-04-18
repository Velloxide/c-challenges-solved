/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 10:09:54 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/18 11:41:45 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	nb;
	int	signal;

	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	signal = 1;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	nb = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (nb * signal);
}

int	check_formula(int argc, char **argv, int *nb)
{
	if (argc < 2 || argv[1][0] != '-' || argv[1][1] != 'c')
		return (-1);
	if (argv[1][2] != '\0')
	{
		*nb = ft_atoi(argv[1] + 2);
		return (2);
	}
	else
	{
		if (argc < 3)
			return (-1);
		*nb = ft_atoi(argv[2]);
		return (3);
	}
}

void	ft_print_header(char *filename, int file_index, int start_index)
{
	if (file_index > start_index)
		write(1, "\n", 1);
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==\n");
}

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
