/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:28:40 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:28:42 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	nu;

	if (nb > 9)
		ft_putnbr(nb / 10);
	nu = (nb % 10) + '0'; 
	write(1, &nu, 1);
	return ;
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
		{
			write(1, "fizzbuzz\n", 9);
		}
		else if (i % 3 == 0)
		{
			write(1, "fizz\n", 5);
		}
		else if (i % 5 == 0)
		{
			write(1, "buzz\n", 5);
		}

		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
	return 0;
}
