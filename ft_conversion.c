/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:34:47 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:34:48 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_conv_dioux(va_list ap, t_flags *f)
{
	if (f->conv == 'O')
		ft_ou(ap, f);
	else if (f->conv == 'o')
		ft_modif_oux(ap, f);
	else if (f->conv == 'u')
		ft_modif_oux(ap, f);
	else if (f->conv == 'U')
		ft_ou(ap, f);
	else if (f->conv == 'x')
		ft_modif_oux(ap, f);
	else if (f->conv == 'X')
		ft_modif_oux(ap, f);
	else if (f->conv == 'O')
		ft_modif_oux(ap, f);
	else if (f->conv == 'o')
		ft_modif_oux(ap, f);
	else if (f->conv == 'd')
		ft_modif_id(ap, f);
	else if (f->conv == 'D')
		ft_d(ap, f);
	else if (f->conv == 'i')
		ft_modif_id(ap, f);
	return (0);
}

static	int		ft_conv_scp(va_list ap, t_flags *f)
{
	if (f->conv == 's' || f->conv == 'S')
		ft_modif_sc(ap, f);
	else if (f->conv == 'c' || f->conv == 'C')
		ft_modif_sc(ap, f);
	else if (f->conv == 'p')
		ft_point(ap, f);
	else if (f->conv == '%')
		ft_percen(f);
	return (0);
}

int				ft_conv(va_list ap, t_flags *f)
{
	if (ft_strchr("dDiOouUxX", f->conv))
		ft_conv_dioux(ap, f);
	else if (ft_strchr("sScCp%", f->conv))
		ft_conv_scp(ap, f);
	return (0);
}
