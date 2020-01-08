/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:35:56 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:35:57 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_ll_di(va_list ap, t_flags *f)
{
	long	long	int	i;
	char				*str;

	i = va_arg(ap, long long int);
	if (i == 0 && (f->pre > -1 || f->champs > 0) && (!(f->attr)))
	{
		ft_flag_zero(f);
		return (0);
	}
	if (i < 0)
	{
		i = i * -1;
		str = ft_itoa_base(i, 10);
		ft_neg(str, f);
		return (0);
	}
	str = ft_itoa_base(i, 10);
	ft_attr_id(str, f);
	return (0);
}

static	int		ft_h_di(va_list ap, t_flags *f)
{
	short	int	i;
	char		*str;

	i = (short int)va_arg(ap, int);
	if (i == 0 && (f->pre > -1 || f->champs > 0) && (!(f->attr)))
	{
		ft_flag_zero(f);
		return (0);
	}
	if (i < 0)
	{
		i = i * -1;
		str = ft_itoa_base(i, 10);
		ft_neg(str, f);
	}
	str = ft_itoa_base(i, 10);
	ft_attr_id(str, f);
	return (0);
}

static	int		ft_hh_di(va_list ap, t_flags *f)
{
	signed	char	i;
	char			*str;

	i = (signed char)va_arg(ap, int);
	if (i == 0 && (f->pre > -1 || f->champs > 0) && (!(f->attr)))
	{
		ft_flag_zero(f);
		return (0);
	}
	if (i < 0)
	{
		i = i * -1;
		str = ft_itoa_base(i, 10);
		ft_neg(str, f);
		return (0);
	}
	str = ft_itoa_base(i, 10);
	ft_attr_id(str, f);
	return (0);
}

static	int		ft_void_di(va_list ap, t_flags *f)
{
	ssize_t		i;
	char		*str;

	i = va_arg(ap, int);
	if (i == 0 && (f->pre > -1 || f->champs > 0) && (!(f->attr)))
	{
		while (f->champs > 1)
		{
			write(1, " ", 1);
			f->champs--;
		}
		ft_putchar('0');
		return (0);
	}
	if (i < 0)
	{
		i = i * -1;
		str = ft_itoa_base(i, 10);
		ft_neg(str, f);
		return (0);
	}
	str = ft_itoa_base(i, 10);
	ft_attr_id(str, f);
	return (0);
}

int				ft_modif_id(va_list ap, t_flags *f)
{
	if (!(f->modif))
		ft_void_di(ap, f);
	else if (f->modif[0] == 'h' && f->modif[1] == 'h')
		ft_hh_di(ap, f);
	else if (f->modif[0] == 'h')
		ft_h_di(ap, f);
	else if (f->modif[0] == 'l' && f->modif[1] == 'l')
		ft_ll_di(ap, f);
	else
		ft_modif_id2(ap, f);
	return (0);
}
