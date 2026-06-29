/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:12:37 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/08 18:43:30 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
//#include <stdlib.h>
//#include <stdio.h>


void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;

	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
/*
void	f(void *data)
{
	printf("-----\nNode: %s\n", (char *)data);
}

t_list	*ft_creatNode(void *data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int	main(int ac, char **av)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*head;
	t_list	*tmp;
	if (ac == 3)
	{
		node1 = ft_creatNode(av[1]);
		node2 = ft_creatNode(av[2]);
		head = node1;
		node1->next = node2;
		node2->next = NULL;
		ft_list_foreach(head, f);
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
	return (0);
}
*/
