/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_and_flip.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:06:41 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/03/09 23:18:31 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_replace_and_flip(char *str)
{
	//$>./a.out "Run   go fast go  and lO jump go  here" | cat -e
	//	     Run   Lo  fast Lo  and 11 go jump Lo   here \n$>
	
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	char	*arry;
	arry = ft_replace_and_flip(argv[1]);
	return (0);
}
