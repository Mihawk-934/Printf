/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_big_dou.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:35:44 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:35:45 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d(va_list ap, t_flags *f)
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

int		ft_ou(va_list ap, t_flags *f)
{
	unsigned	long	int	i;
	char					*str;

	i = (unsigned long int)va_arg(ap, unsigned long int);
	if (i == 0 && (f->pre > -1 || f->champs > 0))
	{
		ft_flag_zero(f);
		return (0);
	}
	if (f->conv == 'O')
		str = ft_itoa_base(i, 8);
	else
		str = ft_itoa_base(i, 10);
	ft_attr_oux(str, f);
	return (0);
}
