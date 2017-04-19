/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaypars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:54:13 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 13:59:13 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		displaypars(t_list *new)
{
	int		i;

	i = -1;
	while (new->all[++i] != NULL)
	{
		ft_putstr(new->all[i]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
	return (1);
}
