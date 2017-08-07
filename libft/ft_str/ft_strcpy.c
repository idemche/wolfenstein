/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemche <idemche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:25:08 by idemchen          #+#    #+#             */
/*   Updated: 2017/07/01 02:08:04 by idemche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	char *s;

	s = dst;
	if (!src)
		return (NULL);
	while ((*s++ = *src++) != 0)
		;
	return (dst);
}
