/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:24:31 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 15:03:56 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		main(void)
{
	t_list *new;

	new = initlist();
	launchread(new);
	takeallpath(new, new->end, 0);
	removepath(new);
	if (new->pathlen <= 0)
	{
		freepars(new);
		free(new);
		return (error());
	}
	keepbestpath(new);
	display(new);
	freeall(new);
	return (1);
}
