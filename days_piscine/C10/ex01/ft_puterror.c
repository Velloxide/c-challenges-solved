/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:14:29 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/07 22:13:38 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_puterror(char *err, int dut)
{
	int	size;
	
	size = 0;
	while (err[size])
		size++;
	ft_putstr_size(err, 2, size);
	if (dut == 1)
		ft_putstr_size(": ", 2, 2);
	else if (dut == 0)
		ft_putstr_size("\n", 2, 1);
}
