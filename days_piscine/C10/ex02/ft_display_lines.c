/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:17:18 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/01 22:18:09 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_tail.h"

void	ft_copy_line(char *temp_line, char **lines, int length, int target_index)
{
	int	j;

	if (lines[target_index] != NULL)
		free(lines[target_index]);
	lines[target_index] = malloc((length + 1) * sizeof(char));
	if (!lines[target_index])
		return ;
	j = 0;
	while (j < length)
	{
		lines[target_index][j] = temp_line[j];
		j++;
	}
	lines[target_index][length] = '\0';
}

void	ft_print_and_free(char **lines, int total_lines, int nb)
{
	int	k;
	int	start;
	int	count;

	if (total_lines < nb)
	{
		count = total_lines;
		start = 0;
	}
	else
	{
		count = nb;
		start = total_lines % nb;
	}
	k = 0;
	while (k < count)
	{
		if (lines[(start + k) % nb])
		{
			ft_putstr_fd(lines[(start + k) % nb], 1);
			write(1, "\n", 1);
		}
		k++;
	}
	k = 0;
	while (k < nb)
	{
		if (lines[k])
			free(lines[k]);
		k++;
	}
	free(lines);
}

void	ft_display_lines(int fd, int nb)
{
	int	total_lines;
	int	length;
	char	c;
	char	**lines;
	char	temp_line[4096];

	lines = malloc(sizeof(char *) * nb);
	if (!lines)
		return;
	length = 0;
	while (length <= nb - 1)
		lines[length++] = NULL;
	total_lines = 0;
	length = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			temp_line[length] = '\0';
			ft_copy_line(temp_line, lines, length, total_lines % nb);
			length = 0;
			total_lines++;
		}
		else
			temp_line[length++] = c;
	}
	if (length > 0)
	{
		temp_line[length % 4096] = '\0';
		ft_copy_line(temp_line, lines, length, total_lines % nb);
		total_lines++;
	}
	ft_print_and_free(lines, total_lines, nb);
}
