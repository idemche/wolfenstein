/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:20:02 by idemche           #+#    #+#             */
/*   Updated: 2017/07/31 18:41:54 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_split_count(char **split)
{
	size_t		count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}
