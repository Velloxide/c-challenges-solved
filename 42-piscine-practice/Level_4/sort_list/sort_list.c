/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 21:09:24 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/16 23:06:20 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	temp;
	t_list	*crr;
	t_list	*nextNode;

	crr = lst;
	while (crr && crr->next)
	{
		nextNode = crr->next;
		if (!cmp(crr->data, nextNode->data))
		{
			temp = crr->data;
			crr->data = nextNode->data;
			nextNode->data = temp;
			crr = lst;
		}
		else
			crr = crr->next;
	}
	return (lst);
}
/*
int	ft_cmp(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

t_list	*ft_creatnode(int a)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = a;
	node->next = NULL;
	return (node);
}

void	ft_printlist(t_list *head)
{
	t_list	*crr;

	crr = head;
	while (crr)
	{
		printf("%d\n", crr->data);
		crr= crr->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*head;

	node1 = ft_creatnode(1);
	node2 = ft_creatnode(2);
	node3 = ft_creatnode(3);
	node4 = ft_creatnode(4);

	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	sort_list(head, ft_cmp);
	ft_printlist(head);
	return (0);
}
*/
