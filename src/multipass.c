/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:43:08 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 14:43:00 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		keepbestpath(t_list *new)
{
	new->bestpath = malloc(sizeof(int*) * 4);
	new->bestpath[0] = malloc(sizeof(int) * (new->pathlen));
	new->bestpath[1] = malloc(sizeof(int) * (new->pathlen));
	new->bestpath[2] = malloc(sizeof(int) * (new->pathlen));
	new->bestpath[3] = malloc(sizeof(int) * (new->pathlen));
	init_bestpath(new, 0, -1);
	init_bestpath(new, 1, 0);
	fillpathlen(new);
	takeotherpath(new, 0);
	return (1);
}

int		takeotherpath(t_list *new, int x)
{
	int		tmp;

	if (x == new->pathlen)
	{
		tmp = sendants(new);
		if (new->pathmin == -1 || tmp < new->pathmin)
		{
			new->pathmin = tmp;
			tmp = -1;
			while (++tmp < new->pathlen)
				new->bestpath[3][tmp] = new->bestpath[1][tmp];
		}
		init_bestpath(new, 1, 0);
		return (1);
	}
	if (canaddpath(new, x) == 1)
	{
		new->bestpath[0][x] = 1;
		takeotherpath(new, x + 1);
		new->bestpath[0][x] = -1;
	}
	takeotherpath(new, x + 1);
	return (1);
}

int		sendants(t_list *new)
{
	int		nb;
	int		tmp;

	nb = new->nbrant;
	while (--nb >= 0)
	{
		tmp = takemin(new);
		new->bestpath[1][tmp]++;
	}
	return (new->bestpath[1][tmp] + new->bestpath[2][tmp]);
}

int		takemin(t_list *new)
{
	int		min[2];
	int		i;
	int		tmp;

	min[0] = -1;
	i = -1;
	while (++i < new->pathlen)
	{
		tmp = new->bestpath[2][i] + new->bestpath[1][i];
		if (new->bestpath[0][i] >= 0 && (min[0] == -1 || tmp < min[0]))
		{
			min[0] = tmp;
			min[1] = i;
		}
	}
	return (min[1]);
}

int		canaddpath(t_list *new, int x)
{
	int		i;

	i = -1;
	while (++i < new->pathlen)
	{
		if (i != x && new->bestpath[0][i] >= 1
		&& tabtabchr(new->path[x], new->path[i]) == 0)
			return (0);
	}
	return (1);
}
