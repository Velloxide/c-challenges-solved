/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Itachi-Logic <ILogic@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:29:07 by Itachi-Logic      #+#    #+#             */
/*   Updated: 2025/12/01 21:29:08 by Itachi-Logic     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *restrict dst, const char *restrict src)
{
	char	*bidst;

	if (dst == src)
		return dst;
	bidst = dst;
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (bidst);
}
/*
int	main(void)
{
	char	src[] = "boutayeb";
	char	dest[50] = "said";
	
	printf("this is old dest: %s\n", dest);
	ft_strcpy(dest, src);
	printf("this is new dest: %s\n", dest);
}
*/
