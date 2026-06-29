/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:17:16 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/08 03:55:29 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
/*
t_list	*creat_new_node(char *old_str)
{
	t_list	*newNode;
	
	newNode = (t_list *)malloc(sizeof(t_list));
	if (!newNode)
		return (NULL);
	newNode->data = old_str;
	newNode->next = NULL;
	return (newNode);
}

int	main(void)
{
	t_list	*node_1;
	t_list	*node_2;
	t_list	*head;

	node_1 = creat_new_node("1111");
	node_2 = creat_new_node("2222");
	if (!node_2 || !node_1)
		return (0);
	head = node_1;
	node_1->next = node_2;
	node_2->next = NULL;
	printf("count: %i\n", ft_list_size(head));
	free(node_1);
	free(node_2);
	return (0);
}
*/
