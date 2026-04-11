/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:55:36 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/11 09:34:15 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include <errno.h>
#include "ft.h"

void	ft_err_handling(char **argv, int i)
{
	ft_putstr_err(basename(argv[0]));
	write(2, ": ", 2);
	ft_putstr_err(argv[i]);
	write(2, ": ", 2);
	ft_putstr_err(strerror(errno));
	write(2, "\n", 1);
}
