/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:53:07 by idemchen          #+#    #+#             */
/*   Updated: 2017/07/13 20:35:38 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstadd(t_list **alst, t_list *list)
{
	if (alst && list)
		list->next = (*alst);
	*alst = list;
}
