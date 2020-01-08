/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:37:05 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:37:06 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		parse_modif(const char *format, t_flags *f)
{
	int		i;
	int		a;

	a = 0;
	i = 0;
	while (format[i])
	{
		if (ft_strchr("hljz", format[i]))
			a++;
		else
			break ;
		i++;
	}
	if (a > 0)
	{
		if (!(f->modif = (char*)malloc(sizeof(char) * a + 1)))
			return (0);
		f->modif[a] = '\0';
		while (--a >= 0)
			f->modif[a] = format[a];
	}
	f->conv = format[i];
	return (0);
}

static int		parse_pre(const char *format, t_flags *f)
{
	int		i;

	i = 0;
	if (format[0] == '.')
	{
		f->pre = ft_atoi(&format[1]);
		i++;
	}
	while (ft_isdigit(format[i]))
		i++;
	parse_modif(&format[i], f);
	return (0);
}

static int		parse_champs(const char *format, t_flags *f)
{
	int		i;

	i = 0;
	f->champs = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		i++;
	parse_pre(&format[i], f);
	return (0);
}

int				parse(const char *format, t_flags *f)
{
	int		i;
	int		a;

	a = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		if (ft_strchr("#0-+ ", format[i]))
			a++;
		else
			break ;
	}
	if (a > 0)
	{
		if (!(f->attr = (char*)malloc(sizeof(char) * a + 1)))
			return (0);
		f->attr[a] = '\0';
		while (--a >= 0)
			f->attr[a] = format[a];
	}
	parse_champs(&format[i], f);
	return (0);
}
