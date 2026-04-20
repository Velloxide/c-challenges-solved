/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:20:54 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/20 23:00:55 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_tail.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
