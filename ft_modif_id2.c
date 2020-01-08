/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_id2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:36:07 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:36:08 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_l_di(va_list ap, t_flags *f)
{
	long	int	i;
	char		*str;

	i = va_arg(ap, long int);
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

static	int		ft_z_di(va_list ap, t_flags *f)
{
	size_t	i;
	char	*str;
	char	c;

	c = 0;
	i = va_arg(ap, size_t);
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
	str = ft_itoa_base(i, 10);
	ft_attr_id(str, f);
	return (0);
}

static	int		ft_j_di(va_list ap, t_flags *f)
{
	intmax_t	i;
	char		*str;

	i = va_arg(ap, intmax_t);
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

int				ft_modif_id2(va_list ap, t_flags *f)
{
	if (f->modif[0] == 'l')
		ft_l_di(ap, f);
	else if (f->modif[0] == 'j')
		ft_j_di(ap, f);
	else if (f->modif[0] == 'z')
		ft_z_di(ap, f);
	return (0);
}
