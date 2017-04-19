/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeallpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:50:07 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 14:38:58 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		takeallpath(t_list *new, int actual, int x)
{
	int		i;

	i = -1;
	if (actual == new->start)
		return (1);
	while (++i < new->tablen)
	{
		if (new->tab[i][0] == actual
		&& tabchr(new->path[x], new->tab[i][1]) == 0)
			takeallpath(new, new->tab[i][1],
			newpath(new, x, new->tab[i][1]));
		if (new->tab[i][1] == actual
		&& tabchr(new->path[x], new->tab[i][0]) == 0)
			takeallpath(new, new->tab[i][0],
			newpath(new, x, new->tab[i][0]));
	}
	return (1);
}

int		tabchr(int *tab, int x)
{
	int		i;

	i = -1;
	while (tab[++i] >= 0)
	{
		if (tab[i] == x)
			return (1);
	}
	return (0);
}

int		newpath(t_list *new, int x, int toadd)
{
	int		i;

	tabcpy(new);
	i = -1;
	while (new->path[x][++i] >= 0)
		new->path[new->pathlen][i] = new->path[x][i];
	new->path[new->pathlen][i] = toadd;
	new->path[new->pathlen][i + 1] = -2;
	return (new->pathlen++);
}

int		tabcpy(t_list *new)
{
	int		**newp;
	int		i;

	i = -1;
	newp = malloc(sizeof(int*) * (new->pathlen + 1));
	while (++i < new->pathlen)
		newp[i] = new->path[i];
	newp[i] = malloc(sizeof(int) * (new->nbrroom + 1));
	free(new->path);
	new->path = newp;
	return (1);
}
