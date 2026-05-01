/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:14:16 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2026/05/01 21:52:06 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_TAIL
#define FT_TAIL

void	ft_putstr_fd(char *str, int fd);
void	ft_print_header(char *filename, int file_index, int start_index);
void	ft_display_tail(int file_d, int nb);
void	ft_display_error(char *prog_name, char *filename);
int	ft_atoi(char *str);
int	check_formula(int argc, char **argv, int *nb, int *mode);
void	ft_copy_line(char *temp_line, char **lines, int length, int target_index);
void	ft_print_and_free(char **lines, int total_lines, int nb);
void	ft_display_lines(int fd, int nb);

#endif
