/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:41:54 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 14:53:15 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		display(t_list *new)
{
	int		i;

	displaypars(new);
	new->display = malloc(sizeof(int*) * 2);
	new->display[0] = malloc(sizeof(int) * new->nbrant);
	new->display[1] = malloc(sizeof(int) * new->nbrant);
	if (checkone(new) == -1)
	{
		return (1);
	}
	i = -1;
	while (++i < new->nbrant)
		new->display[0][i] = -1;
	setnewvalue(new);
	while (displayvalue(new) > 0)
		setnewvalue(new);
	return (1);
}

int		displayvalue(t_list *new)
{
	int		i;
	int		check;

	i = -1;
	check = 0;
	while (++i < new->nbrant)
	{
		if (new->display[0][i] >= 0)
		{
			if (check != 0)
				ft_putchar(' ');
			ft_putchar('L');
			ft_putnbr(i);
			ft_putchar('-');
			ft_putstr(new->name[new->display[0][i]]);
			check = 1;
		}
	}
	if (check == 0)
		return (-1);
	ft_putchar('\n');
	return (1);
}

int		setnewvalue(t_list *new)
{
	int		i;

	i = -1;
	while (++i < new->nbrant)
	{
		if (new->display[0][i] == new->end)
			new->display[0][i] = -2;
		if (new->display[0][i] >= 0)
			newroom(new, i);
	}
	sendant(new);
	return (1);
}

int		sendant(t_list *new)
{
	int		i;
	int		j;
	int		h;

	i = -1;
	while (++i < new->pathlen)
	{
		if (new->bestpath[3][i] > 0)
		{
			j = 0;
			h = 0;
			while (new->display[0][j] != -1)
				j++;
			while (new->path[i][h] != new->start)
				h++;
			new->display[0][j] = new->path[i][h - 1];
			new->display[1][j] = i;
			new->bestpath[3][i]--;
		}
	}
	return (1);
}

int		newroom(t_list *new, int x)
{
	int		i;

	i = -1;
	while (new->path[new->display[1][x]][i] != new->display[0][x])
		i++;
	if (i == 0)
		new->display[0][x] = new->end;
	else
		new->display[0][x] = new->path[new->display[1][x]][i - 1];
	return (1);
}
