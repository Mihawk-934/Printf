/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:37:54 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:37:56 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_printf2(va_list ap, const char *format, int i, int c)
{
	t_flags		f;

	while (format[++i])
	{
		f = ft_init_struct();
		if (format[i] == '%')
		{
			i++;
			parse(&format[i], &f);
			i += ft_strnlen(&format[i], f.conv);
			ft_conv(ap, &f);
			if (f.attr)
				ft_strdel(&f.attr);
			if (f.modif)
				ft_strdel(&f.modif);
		}
		else
		{
			ft_putchar(format[i]);
			c++;
		}
		c = f.count + c;
	}
	return (c);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			c;

	c = 0;
	i = -1;
	va_start(ap, format);
	c = ft_printf2(ap, format, i, c);
	va_end(ap);
	return (c);
}
