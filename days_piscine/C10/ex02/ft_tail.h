/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:14:16 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/04/20 21:17:35 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_TAIL
#define FT_TAIL

void	ft_putstr(char *str);
void	ft_print_header(char *filename, int file_index, int start_index);
void	ft_display_tail(int file_d, int nb);
int	ft_atoi(char *str);
int	check_formula(int argc, char **argv, int *nb);

#endif
