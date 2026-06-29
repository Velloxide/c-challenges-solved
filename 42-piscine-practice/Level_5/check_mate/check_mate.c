/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 06:14:37 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/22 17:07:36 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	getKingpos(char **bord, int *kingPos)
{
	int	i;
	int	j;

	j = 0;
	while (bord[j])
	{
		i = 0;
		while (bord[j][i])
		{
			if (bord[j][i] == 'K')
			{
				kingPos[0] = i;
				kingPos[1] = j;
			}
			i++;
		}
		j++;
	}
	return ;
}

char	there_enemy(char c)
{
	if (c == 'P' || c == 'B' || c == 'R' || c == 'Q')
		return (c);
	return (0);
}

int	check_direction(char **bord, int *kingPos, int d_x, int d_y)
{
	int	x;
	int	y;
	int	step;
	char	piece;

	x = kingPos[0] + d_x;
	y = kingPos[1] + d_y;
	step = 1;
	while (y >= 0 && x >= 0 && bord[y] && bord[y][x])
	{
		piece = there_enemy(bord[y][x]);
		if (piece != 0)
		{
			if (d_x == 0 || d_y == 0)
			{
				if (piece == 'R' || piece == 'Q')
					return (1);
				return (0);
			}
			else
			{
				if (piece == 'B' || piece == 'Q')
					return (1);
				if (piece == 'P' && d_y == 1 && step == 1)
					return (1);
				return (0);
			}
		}
		x += d_x;
		y += d_y;
		step++;
	}
	return (0);
}

int	ft_check_mate(char **bord)
{
	int	kingPos[2] = {-1, -1};

	getKingpos(bord, kingPos);
	if (check_direction(bord, kingPos, 1, 1))
		return (1);
	else if (check_direction(bord, kingPos, -1, -1))
		return (1);
	else if (check_direction(bord, kingPos, -1, 1))
		return (1);
	else if (check_direction(bord, kingPos, 1, -1))
		return (1);
	else if (check_direction(bord, kingPos, 0, 1))
		return (1);
	else if (check_direction(bord, kingPos, 1, 0))
		return (1);
	else if (check_direction(bord, kingPos, 0, -1))
		return (1);
	else if (check_direction(bord, kingPos, -1, 0))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		argv++;
		if (ft_check_mate(argv))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
	return (0);
}
