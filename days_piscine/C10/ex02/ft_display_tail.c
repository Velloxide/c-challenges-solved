/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tail.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:19:56 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/01 23:28:17 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_display_tail(int file_d, int nb)
{
	int		bytes_read;
	int		total_bytes;
	int		i;
	char	temp_buffer[29696];
	char	*ring_buffer;

	if (nb == 0)
	{
		while (read(file_d, temp_buffer, 29696) > 0);
		return ;
	}
	ring_buffer = malloc(nb * sizeof(char));
	if (!ring_buffer)
		return ;
	bytes_read = read(file_d, temp_buffer, 29696);
	total_bytes = 0;
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			ring_buffer[total_bytes % nb] = temp_buffer[i];
			i++;
			total_bytes++;
		}
		bytes_read = read(file_d, temp_buffer, 29696);
	}
	i = 0;
	if (total_bytes <= nb)
	{
		while (i < total_bytes)
			write(1, &ring_buffer[i++], 1);
	}
	else
	{
		i = total_bytes % nb;
		while (i < nb)
			write(1, &ring_buffer[i++], 1);
		i = 0;
		while (i < (total_bytes % nb))
			write(1, &ring_buffer[i++], 1);
	}
	free(ring_buffer);
}
