/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:58:19 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/07/11 18:51:11 by Velloxide        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_print_comb(void)
{
	int	num0;
	int	num1;
	int	num2;

	num0 = 0;
	while (num0 <= 7)
	{
		num1 = num0 + 1;
		while (num1 <= 8)
		{
			num2 = num1 + 1;
			while (num2 <= 9)
			{
				ft_putchar(num0 + 48);
				ft_putchar(num1 + 48);
				ft_putchar(num2 + 48);
				if (num0 != 7)
					write(1, ", ", 2);
				num2++;
			}
			num1++;
		}
		num0++;
	}
	return ;
}
/*
int	main(void)
{
	ft_print_comb();
	return (0);
}
*/
