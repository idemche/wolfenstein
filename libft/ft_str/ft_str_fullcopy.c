/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fullcopy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemche <idemche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 02:09:17 by idemche           #+#    #+#             */
/*   Updated: 2017/07/01 02:20:10 by idemche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_str_fullcopy(char **dst, const char *src)
{
	ssize_t writer;

	writer = -1;
	if (!src || *dst)
	{
		*dst = (void*)0;
		return ;
	}
	if (!(*dst = (char*)malloc(ft_strlen(src) + 1)))
		return ;
	while (src[++writer])
		(*dst)[writer] = src[writer];
	(*dst)[writer] = '\0';
}
