/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:33:02 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/27 21:33:18 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_help(char *str)
{
	int	len;
	
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

void	ft_print_options(int *options)
{
	int	i;
	char	c;

	i = 31;
	while (i >= 0)
	{
		c = ((*options >> i) & 1) + '0';
		write(1, &c, 1);
		if (i % 8 == 0 && i != 0)
			write(1, " ", 1);
		i--;
	}
	write(1, "\n", 1);
}

int	ft_options(char *str, int *options, int *States)
{
	int	i;
	char	c;

	if (str[0] != '-' || str[1] == '\0')
	{
		*States = 1;
		return (0);
	}
	i = 1;
	while (str[i])
	{
		c = str[i];
		if (c < 'a' || c > 'z')
			*States = 1;
		else
			*options |= 1 << (c - 'a');
		i++;
	}
	if (*options & (1 << ('h' - 'a')))
		*States = 2;
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*help_err;
	int	States;
	int	options;
	int	i;

	help_err = "options: abcdefghijklmnopqrstuvwxyz\n";
	if (argc < 2)
	{
		ft_print_help(help_err);
		return (0);
	}
	options = 0;
	States = 3;
	i = 1;
	while (i < argc)
	{
		ft_options(argv[i], &options, &States);
		if (States == 2)
		{
			ft_print_help(help_err);
			return (0);
		}
		else if (States == 1)
		{
			help_err = "Invalid Option\n";
			ft_print_help(help_err);
			return (0);
		}
		i++;
	}
	ft_print_options(&options);
	return (0);
}
