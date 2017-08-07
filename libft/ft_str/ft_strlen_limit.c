/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_limit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemche <idemche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 01:37:01 by idemche           #+#    #+#             */
/*   Updated: 2017/07/14 01:44:53 by idemche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen_limit(char *str, char limiter)
{
	size_t length;

	length = 0;
	while (str[length] && str[length] != limiter)
		length++;
	return (length);
}
