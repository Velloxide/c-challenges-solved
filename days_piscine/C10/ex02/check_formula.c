/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_formula.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:18:50 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/20 23:19:19 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include "ft_tail.h"

int	check_formula(int argc, char **argv, int *nb)
{
	if (argc < 2 || argv[1][0] != '-' || argv[1][1] != 'c')
		return (-1);
	if (argv[1][2] != '\0')
	{
		*nb = ft_atoi(argv[1] + 2);
		return (2);
	}
	if (argc < 3)
	{
		ft_putstr_fd(basename(argv[0]), 2);
		ft_putstr_fd(": option requires an argument -- 'c'\n", 2);
		ft_putstr_fd("Try '", 2);
		ft_putstr_fd(basename(argv[0]), 2);
		ft_putstr_fd(" --help' for more information.\n", 2);
		return (-1);
	}
	*nb = ft_atoi(argv[2]);
	return (3);
}
