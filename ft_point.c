/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:37:41 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:37:42 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_pointbis(char *str, t_flags *f, int a)
{
	if (f->champs > a + 2)
	{
		f->count = f->count + f->champs;
		while (f->champs > a + 2)
		{
			ft_putchar(' ');
			f->champs--;
		}
		ft_putstr("0x");
		ft_putstr(str);
		return (0);
	}
	f->count = f->count + a + 2;
	ft_putstr("0x");
	ft_putstr(str);
	ft_strdel(&str);
	return (0);
}

static	int		ft_pointflag(char *str, t_flags *f, int a)
{
	if (f->champs > a + 2)
	{
		f->count = f->count + f->champs;
		ft_putstr("0x");
		ft_putstr(str);
		while (f->champs > a + 2)
		{
			ft_putchar(' ');
			f->champs--;
		}
		return (0);
	}
	f->count = f->count + a + 2;
	ft_putstr("0x");
	ft_putstr(str);
	ft_strdel(&str);
	return (0);
}

int				ft_point(va_list ap, t_flags *f)
{
	void	*p;
	size_t	i;
	char	*str;
	int		a;

	a = 0;
	str = NULL;
	p = va_arg(ap, void*);
	i = (size_t)p;
	str = ft_itoa_base(i, 16);
	a = ft_strlen(str);
	if (ft_strchr(f->attr, '-'))
		ft_pointflag(str, f, a);
	else
		ft_pointbis(str, f, a);
	return (0);
}
