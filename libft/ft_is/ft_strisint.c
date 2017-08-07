/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:17:48 by idemche           #+#    #+#             */
/*   Updated: 2017/07/10 18:22:41 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_byte	ft_string_isdigit(char *str)
{
	int length;

	while (SPACED(*str) || TABBED(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	length = ft_strlen(str);
	if (length == 10 && ft_strcmp(str, "2147483647") > 0)
		return (0);
	if (length > 10)
		return (0);
	return (1);
}
