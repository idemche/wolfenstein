/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemche <idemche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 03:50:01 by idemche           #+#    #+#             */
/*   Updated: 2017/07/14 03:53:43 by idemche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					ft_word_count(char const *s, char divider)
{
	unsigned		iter;
	int				words;

	if (!s || !divider)
		return (-1);
	iter = 0;
	words = 0;
	while (s[iter] != '\0')
	{
		while (s[iter] == divider)
			iter++;
		if (s[iter] != '\0')
			words++;
		while (s[iter] && (s[iter] != divider))
			iter++;
	}
	return (words);
}
