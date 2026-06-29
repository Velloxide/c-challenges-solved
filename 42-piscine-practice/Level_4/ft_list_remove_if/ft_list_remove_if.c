/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:56:12 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/09 21:37:08 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
//#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*crr;
	t_list	*tmp;
	t_list	*prev;


	crr = *begin_list;
	prev = NULL;
	while (crr)
	{
		if ((*cmp)(data_ref, crr->data) == 0)
		{
			if (prev == NULL)
				*begin_list = crr->next;
			else
				prev->next = crr->next;
			tmp = crr;
			crr = crr->next;
			free(tmp);
		}
		else
		{
			prev = crr;
			crr = crr->next;
		}
	}
}
/*
t_list	*ft_creatNode(void *data)
{
	t_list	*newNode;

	newNode = malloc(sizeof(t_list));
	if (!newNode)
		return (NULL);
	newNode->data = data;
	newNode->next = NULL;
	return (newNode);
}

int	cmp(void *data_ref, void *data)
{
	char	*da_ref;
	char	*da;

	da_ref = (char *) data_ref;
	da = (char *) data;
	while (*da_ref)
	{
		if (*da != *da_ref)
			return (*da - *da_ref);
		da++;
		da_ref++;
	}
	return (*da - *da_ref);
}

int	main(int ac, char **av)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*head;
	t_list	*crr;
	t_list	*tmp;

	if (ac != 2)
		return (0);
	node1 = ft_creatNode("node1");
	node2 = ft_creatNode("node2");
	node3 = ft_creatNode("node3");
	head = node1;
	node1->next = node2;
	node2->next = node3;
	ft_list_remove_if(&head, av[1], cmp);
	crr = head;
	while (crr)
	{
		tmp = crr->next;
		printf("%s\n", (char *)crr->data);
		free(crr);
		crr = tmp;
	}
	return (0);
}
*/
