/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_champs_and_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:34:36 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:34:37 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_unis(t_flags *f, char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_remp(f->champs - ft_strlen(str));
	tmp2 = ft_strjoin(tmp, str);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (tmp2);
}

static	char	*ft_uniz(t_flags *f, char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_remp0(f->pre - ft_strlen(str));
	tmp2 = ft_strjoin(tmp, str);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (tmp2);
}

char			*ft_chps_and_pre(char *str, t_flags *f)
{
	char *temp;
	char *temp2;

	temp = NULL;
	if (ft_strlen(str) >= f->pre && ft_strlen(str) >= f->champs)
		return (str);
	else if (f->champs > f->pre && f->pre > ft_strlen(str))
	{
		temp = ft_uniz(f, str);
		temp2 = ft_unis(f, temp);
		return (temp2);
	}
	else if (f->pre > f->champs)
		return (ft_uniz(f, str));
	else if (f->champs > f->pre)
		return (ft_unis(f, str));
	return (NULL);
}
