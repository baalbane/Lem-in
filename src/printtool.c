/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 13:47:33 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 15:30:13 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		addtoall(t_list *new, char *s)
{
	int		i;
	char	**newall;

	i = 0;
	while (new->all[i] != NULL)
		i++;
	newall = malloc(sizeof(char*) * (i + 2));
	i = -1;
	while (new->all[++i] != NULL)
		newall[i] = new->all[i];
	newall[i] = s;
	newall[i + 1] = NULL;
	free(new->all);
	new->all = newall;
	return (1);
}

int		checkone(t_list *new)
{
	int		i;
	int		j;

	i = -1;
	while (++i < new->pathlen)
	{
		j = 0;
		while (new->path[i][j] != -2)
			j++;
		if (j == 1)
		{
			printonepath(new);
			return (-1);
		}
	}
	return (1);
}

int		printonepath(t_list *new)
{
	int		i;

	i = -1;
	while (++i < new->nbrant)
	{
		ft_putchar('L');
		ft_putnbr(i);
		ft_putchar('-');
		ft_putstr(new->name[new->end]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
