/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:46:46 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 13:55:20 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

int		findstr(char *str, t_list *new, int *i)
{
	int		j;
	int		h;

	j = -1;
	while (++j < new->nbrroom)
	{
		h = 0;
		while (new->name[j][h] != '\0' && str[*i + h] == new->name[j][h])
			h++;
		if (new->name[j][h] == '\0' &&
			(str[*i + h] == '\0' || str[*i + h] == '-'))
		{
			*i += h;
			return (1);
		}
	}
	return (-1);
}

int		takeid(char *line, t_list *new, int id)
{
	int		i;
	int		j;

	while (id > 0 && line[id - 1] != '-')
		id++;
	j = -1;
	while (++j < new->nbrroom)
	{
		i = 0;
		while (new->name[j][i] != '\0' && line[i + id] != '-'
		&& line[i + id] == new->name[j][i])
			i++;
		if ((id > 0 || line[i + id] == '-') && new->name[j][i] == '\0')
			return (j);
	}
	return (-1);
}

char	*ft_strchr(char *str, char a)
{
	while (*str != '\0' && *str != a)
		str++;
	if (*str == a)
		return (str);
	return (NULL);
}

char	*strcpyspace(char *line)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] != ' ')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (line[++i] != ' ')
		new[i] = line[i];
	new[i] = '\0';
	return (new);
}
