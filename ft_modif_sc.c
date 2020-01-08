/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_sc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:36:38 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:36:40 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_forc(char c, t_flags *f)
{
	if (f->champs == 0)
	{
		ft_putchar(c);
		f->count++;
		return (0);
	}
	f->count = f->count + f->champs;
	if (!(f->attr))
	{
		while (f->champs > 1)
		{
			ft_putchar(' ');
			f->champs--;
		}
		ft_putchar(c);
		return (0);
	}
	ft_putchar(c);
	while (f->champs > 1)
	{
		ft_putchar(' ');
		f->champs--;
	}
	return (0);
}

static	int		ft_modif_c(va_list ap, t_flags *f)
{
	char	c;

	if (ft_strchr(f->modif, 'l') || f->conv == 'C')
		c = (char)va_arg(ap, wchar_t);
	else
	{
		c = va_arg(ap, int);
		ft_forc(c, f);
	}
	return (0);
}

static	int		ft_modif_s(va_list ap, t_flags *f)
{
	char	*str;
	int		a;

	if (ft_strchr(f->modif, 'l') || f->conv == 'S')
		str = (char*)va_arg(ap, wchar_t*);
	else
	{
		str = va_arg(ap, char*);
		if (str == NULL)
		{
			ft_putstr("(null)");
			f->count = f->count + 6;
			return (0);
		}
		a = ft_strlen(str);
		ft_string(str, f, a);
	}
	return (0);
}

int				ft_modif_sc(va_list ap, t_flags *f)
{
	if (ft_strchr("sS", f->conv))
		ft_modif_s(ap, f);
	else if (ft_strchr("cC", f->conv))
		ft_modif_c(ap, f);
	return (0);
}
