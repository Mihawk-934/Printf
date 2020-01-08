/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_oux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:36:18 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:36:19 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_ll_oux(va_list ap, t_flags *f)
{
	unsigned	long	long	int	i;
	char							*str;

	i = va_arg(ap, unsigned long long int);
	if (i == 0 && (f->pre > -1 || f->champs > 0))
	{
		ft_flag_zero(f);
		return (0);
	}
	if (f->conv == 'o' || f->conv == 'O')
		str = ft_itoa_base(i, 8);
	else if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(i, 16);
	else
		str = ft_itoa_base(i, 10);
	if (f->conv == 'X')
		ft_upper(str);
	ft_attr_oux(str, f);
	return (0);
}

static	int		ft_h_oux(va_list ap, t_flags *f)
{
	unsigned	short	int	i;
	char					*str;

	i = (unsigned short int)va_arg(ap, unsigned int);
	if (i == 0 && (f->pre > -1 || f->champs > 0))
	{
		ft_flag_zero(f);
		return (0);
	}
	if (f->conv == 'o' || f->conv == 'O')
		str = ft_itoa_base(i, 8);
	else if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(i, 16);
	else
		str = ft_itoa_base(i, 10);
	if (f->conv == 'X')
		ft_upper(str);
	ft_attr_oux(str, f);
	return (0);
}

static	int		ft_hh_oux(va_list ap, t_flags *f)
{
	unsigned	char	i;
	char				*str;

	i = (unsigned char)va_arg(ap, unsigned int);
	if (i == 0 && (f->pre > -1 || f->champs > 0))
	{
		ft_flag_zero(f);
		return (0);
	}
	if (i == 0)
	{
		ft_putchar(48);
		f->count++;
		return (0);
	}
	if (f->conv == 'o' || f->conv == 'O')
		str = ft_itoa_base(i, 8);
	else if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(i, 16);
	else
		str = ft_itoa_base(i, 10);
	if (f->conv == 'X')
		ft_upper(str);
	ft_attr_oux(str, f);
	return (0);
}

static	int		ft_void_oux(va_list ap, t_flags *f)
{
	unsigned	int	i;
	char			*str;

	i = va_arg(ap, unsigned int);
	if (i == 0 && (f->pre > -1 || f->champs > 0))
	{
		ft_flag_zero(f);
		return (0);
	}
	if (i == 0)
	{
		ft_putchar('0');
		f->count++;
		return (0);
	}
	if (f->conv == 'o' || f->conv == 'O')
		str = ft_itoa_base(i, 8);
	else if (f->conv == 'x' || f->conv == 'X')
		str = ft_itoa_base(i, 16);
	else
		str = ft_itoa_base(i, 10);
	if (f->conv == 'X')
		ft_upper(str);
	ft_attr_oux(str, f);
	return (0);
}

int				ft_modif_oux(va_list ap, t_flags *f)
{
	if (!(f->modif))
		ft_void_oux(ap, f);
	else if (f->modif[0] == 'h' && f->modif[1] == 'h')
		ft_hh_oux(ap, f);
	else if (f->modif[0] == 'h')
		ft_h_oux(ap, f);
	else if (f->modif[0] == 'l' && f->modif[1] == 'l')
		ft_ll_oux(ap, f);
	else
		ft_modif_oux2(ap, f);
	return (0);
}
