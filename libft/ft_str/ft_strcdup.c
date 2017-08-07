/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemche <idemche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 00:02:15 by idemche           #+#    #+#             */
/*   Updated: 2017/07/02 15:35:01 by idemche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_malloc_until(const char *s, char chr)
{
	char	*str;
	int		iter;

	iter = -1;
	if (!s)
		return (NULL);
	while (s[++iter] && s[iter] != chr)
		;
	if (!(str = (char *)malloc(iter + 1)))
		return (NULL);
	iter = -1;
	while (s[++iter] && s[iter] != chr)
		str[iter] = s[iter];
	str[iter] = 0;
	return (str);
}
