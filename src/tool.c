/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:47:18 by baalbane          #+#    #+#             */
/*   Updated: 2016/10/28 13:57:24 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		ft_strlen(char *a)
{
	int i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

int		ft_putstr(char *a)
{
	int		i;

	i = -1;
	while (a[++i] != '\0')
		ft_putchar(a[i]);
	return (1);
}

int		ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
	return (1);
}

int		ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int		initint(int *i, int *j)
{
	*i = -1;
	*j = 0;
	return (1);
}
