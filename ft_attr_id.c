/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attr_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:33:57 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:33:58 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putstrattr(char *str, t_flags *f)
{
	ft_putstr(str);
	f->count = ft_strlen(str);
	ft_strdel(&str);
}

static	char	*ft_zero(char *str, t_flags *f)
{
	int		i;

	i = 0;
	if (f->pre != -1)
		return (str);
	while (str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

static	char	*ft_plus(char *str, t_flags *f, int a)
{
	char	*tmp;
	int		i;

	i = 0;
	if (f->pre >= f->champs)
	{
		tmp = ft_strjoin("+", str);
		ft_strdel(&str);
		return (tmp);
	}
	if (ft_strchr(f->attr, '0'))
		str = ft_zero(str, f);
	while (str[i] == ' ')
		i++;
	if (i != 0)
		str[i - 1] = '+';
	else if (f->champs > a)
		str[i] = '+';
	else
	{
		tmp = ft_strjoin("+", str);
		ft_strdel(&str);
		return (tmp);
	}
	return (str);
}

static	char	*ft_espace(char *str, t_flags *f, int a)
{
	char	*tmp;

	if (f->pre >= f->champs)
	{
		tmp = ft_strjoin(" ", str);
		ft_strdel(&str);
		return (tmp);
	}
	if (ft_strchr(f->attr, '0'))
		str = ft_zero(str, f);
	if (f->champs > a)
		str[0] = ' ';
	else
	{
		tmp = ft_strjoin(" ", str);
		ft_strdel(&str);
		return (tmp);
	}
	return (str);
}

int				ft_attr_id(char *str, t_flags *f)
{
	char	*finish;
	char	*strattr;
	int		a;

	a = ft_strlen(str);
	strattr = NULL;
	finish = ft_chps_and_pre(str, f);
	if (!(f->attr))
	{
		ft_putstr(finish);
		f->count = ft_strlen(finish);
		ft_strdel(&finish);
		return (0);
	}
	else if (ft_strchr(f->attr, '-'))
		strattr = ft_moins(finish, f, a);
	else if (ft_strchr(f->attr, '+'))
		strattr = ft_plus(finish, f, a);
	else if (ft_strchr(f->attr, ' '))
		strattr = ft_espace(finish, f, a);
	else if (ft_strchr(f->attr, '0'))
		strattr = ft_zero(finish, f);
	ft_putstrattr(strattr, f);
	return (0);
}
