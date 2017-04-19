/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:32:16 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/19 17:41:39 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int	removepath(t_list *new)
{
	int		i;
	int		j;
	int		**newtab;

	initint(&i, &j);
	while (++i < new->pathlen)
	{
		if (isgoodpath(new, new->path[i]) == 1)
			j++;
	}
	newtab = malloc(sizeof(int*) * j);
	initint(&i, &j);
	while (++i < new->pathlen)
	{
		if (isgoodpath(new, new->path[i]) == 1)
		{
			newtab[j] = malloc(sizeof(int) * (new->nbrroom + 1));
			tabcpy2(newtab[j++], new->path[i]);
		}
		free(new->path[i]);
	}
	free(new->path);
	new->path = newtab;
	new->pathlen = j;
	return (1);
}

int	tabcpy2(int *new, int *tab)
{
	int	i;

	i = -1;
	while (tab[++i] >= 0)
		new[i] = tab[i];
	new[i] = -2;
	return (1);
}

int	isgoodpath(t_list *new, int *tab)
{
	int i;

	i = 0;
	while (tab[i] >= 0)
		i++;
	if (i > 0 && tab[i - 1] == new->start)
		return (1);
	return (0);
}
