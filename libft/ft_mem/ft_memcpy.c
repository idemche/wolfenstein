/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemche <idemche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:43:15 by idemchen          #+#    #+#             */
/*   Updated: 2017/07/01 02:07:31 by idemche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*ssrc;

	cdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	if (!src)
		return (NULL);
	while (n > 0)
	{
		*cdst++ = *ssrc++;
		n--;
	}
	return (dst);
}
