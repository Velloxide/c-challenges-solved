/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:27:14 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:27:16 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	c;
	int	i;

	c = 'z';
	i = 1;
	while (c >= 'a')
	{
		if (i % 2 == 0)
			ft_putchar(c - 32);
		else
			ft_putchar(c);
		i++;
		c--;
	}
	if ((c + 1) == 'a')
		ft_putchar('\n');
	return (0); 
}
