/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:37:20 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:37:21 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_perce(t_flags *f)
{
	f->count = f->count + f->champs;
	if (!(f->attr))
	{
		while (f->champs > 1)
		{
			ft_putchar(' ');
			f->champs--;
		}
		ft_putchar('%');
	}
	else if (ft_strchr(f->attr, '-'))
	{
		ft_putchar('%');
		while (f->champs > 1)
		{
			ft_putchar(' ');
			f->champs--;
		}
	}
	return (0);
}

int				ft_percen(t_flags *f)
{
	if (f->champs == 0)
	{
		ft_putchar('%');
		f->count++;
		return (0);
	}
	else
		ft_perce(f);
	return (0);
}
