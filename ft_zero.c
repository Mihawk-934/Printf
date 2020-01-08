/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:41:26 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:41:27 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_flag_zero_plus(t_flags *f)
{
	if (f->champs > f->pre)
	{
		f->count = f->count + f->champs;
		while (f->champs > f->pre)
		{
			ft_putchar(' ');
			f->champs--;
		}
		while (f->pre > 0)
		{
			ft_putchar('0');
			f->pre--;
		}
	}
	if (f->pre > f->champs)
	{
		f->count = f->count + f->champs;
		while (f->pre > 0)
		{
			ft_putchar('0');
			f->pre--;
		}
	}
}

int				ft_flag_zero(t_flags *f)
{
	if (f->pre == 0 && f->champs == 0)
		if (ft_strchr(f->attr, '#') && f->conv == 'o')
		{
			ft_putchar('0');
			f->count++;
			return (0);
		}
	if (f->pre > 0)
		ft_flag_zero_plus(f);
	else if (f->champs > 0)
	{
		f->count = f->count + f->champs;
		while (f->champs > 0)
		{
			ft_putchar(' ');
			f->champs--;
		}
	}
	return (0);
}
