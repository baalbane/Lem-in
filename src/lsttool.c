/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:42:27 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 14:15:20 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

t_list	*initlist(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->nbrroom = 0;
	new->tablen = 0;
	new->start = -1;
	new->end = -1;
	new->pathlen = 1;
	new->pathmin = -1;
	new->path = malloc(sizeof(int*) * 1);
	new->path[0] = malloc(sizeof(int) * 2);
	new->path[0][0] = new->end;
	new->path[0][1] = -2;
	new->all = malloc(sizeof(char*));
	new->all[0] = NULL;
	return (new);
}

int		freeall(t_list *lst)
{
	int		i;

	i = -1;
	while (++i < 4)
		free(lst->bestpath[i]);
	free(lst->bestpath);
	free(lst->display[0]);
	free(lst->display[1]);
	free(lst->display);
	freepars(lst);
	free(lst);
	return (1);
}

int		freepars(t_list *new)
{
	int		i;

	i = -1;
	while (++i < new->tablen)
		free(new->tab[i]);
	if (new->tablen > 0)
		free(new->tab);
	i = -1;
	while (++i < new->nbrroom)
		free(new->name[i]);
	if (new->nbrroom > 0)
		free(new->name);
	i = -1;
	while (++i < new->pathlen)
		free(new->path[i]);
	if (new->pathlen > 0)
		free(new->path);
	i = -1;
	while (new->all[++i] != NULL)
		free(new->all[i]);
	free(new->all[i]);
	free(new->all);
	return (1);
}

int		init_bestpath(t_list *new, int x, int y)
{
	int		i;

	i = -1;
	while (++i < new->pathlen)
		new->bestpath[x][i] = y;
	return (1);
}

int		fillpathlen(t_list *new)
{
	int		len;
	int		i;

	i = -1;
	while (++i < new->pathlen)
	{
		len = 0;
		while (new->path[i][len] >= 0)
			len++;
		new->bestpath[2][i] = len;
	}
	return (1);
}
