/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printNode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 22:47:04 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/06/08 03:53:12 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	void		*data;
}		t_list;

t_list	*create_new_node(void *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));

	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}

int	main(int argc, char *argv[])
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*head;

	node1 = create_new_node("NODE_1");
	node2 = create_new_node("NODE_2");
	node3 = create_new_node("NODE_3");
	node4 = create_new_node("NODE_4");
	if (!node1 || !node2 || !node3 || !node4)
        	return (0);
	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	t_list *current = head;
	while (current != NULL)
	{
		printf("print data: %s\n", (char *)current->data);
		current = current->next;
	}
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return (0);
}
