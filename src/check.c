/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:47:40 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 15:30:11 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		addroom(char *line, t_list *lst)
{
	int		i;
	char	**new;

	new = malloc(sizeof(char*) * (lst->nbrroom + 1));
	i = -1;
	while (++i < lst->nbrroom)
		new[i] = lst->name[i];
	new[i] = strcpyspace(line);
	if (lst->nbrroom > 0)
		free(lst->name);
	lst->name = new;
	lst->nbrroom++;
	return (1);
}

int		addtube(char *line, t_list *lst)
{
	int		i;
	int		**new;

	new = malloc(sizeof(int*) * (lst->tablen + 1));
	i = -1;
	while (++i < lst->tablen)
		new[i] = lst->tab[i];
	new[i] = malloc(sizeof(int) * 2);
	new[i][0] = takeid(line, lst, 0);
	new[i][1] = takeid(line, lst, 1);
	if (lst->tablen > 0)
		free(lst->tab);
	lst->tab = new;
	lst->tablen++;
	return (1);
}

int		isroomline(char *line)
{
	int		i;

	i = 0;
	if (line[0] == 'L' || line[0] == '#')
		return (-1);
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	if (line[i] != ' ' || ((line[i + 1] < '0' || line[i + 1] > '9')
		&& line[i + 1] != '-' && line[i + 1] != '+'))
		return (-1);
	i += 2;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != ' ' || ((line[i + 1] < '0' || line[i + 1] > '9')
		&& line[i + 1] != '-' && line[i + 1] != '+'))
		return (-1);
	i += 2;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] == '\0')
		return (1);
	return (-1);
}

int		istubeline(char *line, t_list *new)
{
	int		i;

	i = 0;
	if (findstr(line, new, &i) == -1)
		return (-1);
	if (line[i++] != '-')
		return (-1);
	if (findstr(line, new, &i) == -1)
		return (-1);
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int		tabtabchr(int *tab, int *tab2)
{
	int		i;

	i = -1;
	while (tab[++i + 1] >= 0)
	{
		if (tabchr(tab2, tab[i]) == 1)
			return (0);
	}
	return (1);
}
