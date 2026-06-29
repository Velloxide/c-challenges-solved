/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:35:12 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/16 21:05:47 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *tab, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[end];
	i = start;
	j = start - 1;
	while (i < end)
	{
		if (tab[i] <= pivot)
			ft_swap(&tab[i], &tab[++j]);
		i++;
	}
	ft_swap(&tab[j + 1], &tab[end]);
	return (j + 1);
}

void	ft_quick_sort(int *tab, int start, int end)
{
	int	pivot_index;

	if (start >= end)
		return;
	pivot_index = partition(tab, start, end);
	ft_quick_sort(tab, start, pivot_index - 1);
	ft_quick_sort(tab, pivot_index + 1, end);
	return;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	if (size <= 1)
		return ;
	ft_quick_sort(tab, 0, (int)size - 1);
}
/*
void trace_print(int *tab, int start, int end)
{
	int i;

	i = start;
	printf("[");
	while (i <= end && i >= 0)
	{
		printf("%d", tab[i++]);
		if (i <= end)
			printf(",");
	}
	printf("]\n");
}

int	main(void)
{
	int	tab[] = {9, 1, 2, 6, 4, 7, 3 ,3, 5, 0, 8};
	printf("Tab before: ");
	trace_print(tab, 0, 10);
	sort_int_tab(tab, 11);
	printf("Tab after:  ");
	trace_print(tab, 0, 10);
	return (0);
}
*/
