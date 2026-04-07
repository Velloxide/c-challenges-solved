/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:55:36 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/07 22:57:59 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libgen.h>
#include <errno.h>
#include "ft.h"

void	ft_err_handling(char **argv, int i)
{
	ft_puterror(basename(argv[0]), 1);
	ft_puterror(argv[i], 1);
	ft_puterror(strerror(errno), 0);
}
