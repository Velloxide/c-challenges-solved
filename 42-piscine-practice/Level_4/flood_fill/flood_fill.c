/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 17:02:33 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/29 21:51:48 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"
#include "flood_fill.h"

void	ft_fill_helper(char **tab, t_point size, t_point curr, char target)
{
	t_point	up;
	t_point	down;
	t_point	lift;
	t_point	right;

	if (curr.y >= size.y || (curr.y < 0 || curr.x < 0) || curr.x >= size.x)
		return ;
	if (tab[curr.y][curr.x] != target)
		return ;
	tab[curr.y][curr.x] = 'F';
	up.y = curr.y - 1;
	up.x = curr.x;
	down.y = curr.y + 1;
	down.x = curr.x;
	lift.x = curr.x - 1;
	lift.y = curr.y;
	right.x = curr.x + 1;
	right.y = curr.y;
	ft_fill_helper(tab, size, up, target);
	ft_fill_helper(tab, size, down, target);
	ft_fill_helper(tab, size, lift, target);
	ft_fill_helper(tab, size, right, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	ft_fill_helper(tab, size, begin, tab[begin.y][begin.x]);
}
