/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:11:44 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/07 22:34:05 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	ft_display_content(int openf)
{
	char	buffer[29696];
	int	bytes_read;

	bytes_read = read(openf, buffer, 29696);
	while (bytes_read > 0)
	{
		ft_putstr_size(buffer, 1, bytes_read);
		bytes_read = read(openf, buffer, 29696);
	}
	if (bytes_read == -1)
		return (-1);
	return (0);
}
