/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_oux2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:36:29 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:36:30 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_l_oux(va_list ap, t_flags *f)
{
	unsigned	long	int	i;
	char					*str;

	i = (unsigned long int)va_arg(ap, unsigned long int);
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

static	int		ft_z_oux(va_list ap, t_flags *f)
{
	size_t	i;
	char	*str;

	i = va_arg(ap, size_t);
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

static	int		ft_j_oux(va_list ap, t_flags *f)
{
	uintmax_t	i;
	char		*str;

	i = va_arg(ap, uintmax_t);
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

int				ft_modif_oux2(va_list ap, t_flags *f)
{
	if (f->modif[0] == 'l')
		ft_l_oux(ap, f);
	else if (f->modif[0] == 'j')
		ft_j_oux(ap, f);
	else if (f->modif[0] == 'z')
		ft_z_oux(ap, f);
	return (0);
}
