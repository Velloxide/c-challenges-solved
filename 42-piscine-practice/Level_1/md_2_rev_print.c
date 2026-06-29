/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md_2_rev_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:31:52 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:31:55 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main (int ac, char *av[])
{
	char	*str;
	int	len;

	if (ac == 2)
	{
		
		str = av[1];
		len = 0;
		while (str[len])
			len++;
		len -= 1;
		while (len >= 0)
			write(1, &str[len--], 1);
	}
	write (1, "\n", 1);
	return (0);
}
