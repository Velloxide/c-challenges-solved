/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:53:31 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/29 21:57:23 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_functions.h"
#include "flood_fill.h"

void	ft_print_tab(char **area, t_point *size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size->y))
	{
		j = 0;
		while (j < (size->x))
		{
			write(1, &(area[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_freeAll(char **area, int i)
{
	while (i >= 0)
		free(area[i--]);
	free(area);
}

char	**ft_make_area(char **zone, t_point size)
{
	char	**area;
	int	i;
	int	j;

	area = malloc(size.y * sizeof(char *));
	if (!area)
		return (NULL);
	i = 0;
	while (i < size.y)
	{
		area[i] = malloc((size.x + 1) * sizeof(char));
		if (!area[i])
		{
			ft_freeAll(area, i - 1);
			return (NULL);
		}
		j = 0;
		while (j < size.x)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		area[i][j] = '\0';
		i++;
	}
	return (area);
}

int	main(void)
{
	char	**area;
	t_point	size = { 8, 5 };
	t_point	begin = { 2, 2 };
	char	*zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10010001",
		"10100001"
	};
	write(1, "----------The Zone---------\n", 28);
	ft_print_tab(zone, &size);
	write(1, "----------The Area---------\n", 28);
	area = ft_make_area(zone, size);
	ft_print_tab(area, &size);
	flood_fill(area, size, begin);
	write(1, "=============Result============\n", 32);
	ft_print_tab(area, &size);
	return (0);
}
