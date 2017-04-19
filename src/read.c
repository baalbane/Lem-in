/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:49:13 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 15:30:18 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		launchread(t_list *new)
{
	char	*str;

	if (getantnbr(new) == -1)
		return (-1);
	while (get_next_line(0, &str))
	{
		if (addline(str, new) == -1)
			return (-1);
		addtoall(new, str);
	}
	return (1);
}

int		addline(char *str, t_list *new)
{
	if (ft_strcmp(str, "##start") == 1)
	{
		if (new->start != -1 || new->end == new->nbrroom)
			return (-1);
		new->start = new->nbrroom;
	}
	else if (ft_strcmp(str, "##end") == 1)
	{
		if (new->end != -1 || new->start == new->nbrroom)
			return (-1);
		new->end = new->nbrroom;
	}
	else if (isroomline(str) != -1)
		addroom(str, new);
	else if (istubeline(str, new) != -1)
		addtube(str, new);
	else if (str[0] != '#')
		return (-1);
	return (0);
}

int		getantnbr(t_list *new)
{
	char	*str;
	int		i;
	int		nbr;

	nbr = 0;
	get_next_line(0, &str);
	if (!str || str[0] == '\0')
		return (-1);
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			free(str);
			return (-1);
		}
		nbr = nbr * 10 + str[i] - '0';
	}
	new->nbrant = nbr;
	addtoall(new, str);
	return (1);
}

int		error(void)
{
	write(1, "error\n", 6);
	return (-1);
}
