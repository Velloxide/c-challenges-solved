/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:19:40 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/20 21:19:42 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

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
