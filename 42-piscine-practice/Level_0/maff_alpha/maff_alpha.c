/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:27:00 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:27:02 by Itachi-Logic     ###   ########.fr       */
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

	c = 'a';
	while (c <= 'z')
	{
		if (c % 2 == 0)
			ft_putchar(c - 32);
		else
			ft_putchar(c);
		c++;
	}
	if ((c - 1) == 'z')
		ft_putchar('\n');
	return (0);
}
