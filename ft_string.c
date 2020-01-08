/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:39:53 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:39:55 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char		*ft_minus(char *str, t_flags *f, int a)
{
	int		i;

	if (f->pre > 0 && f->pre < a)
		a = f->pre;
	if (f->pre == 0)
		return (str);
	i = 0;
	if (!(str))
		return (NULL);
	if (f->champs <= a)
		return (str);
	while (str[f->champs - a] != '\0')
	{
		str[i] = str[f->champs - a];
		i++;
		f->champs++;
	}
	while (str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

static	char		*ft_dup(char *str)
{
	char	*dup;
	int		i;

	dup = NULL;
	i = 0;
	if (!(str))
		return (NULL);
	if (!(dup = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static	char		*ft_str(char *str, t_flags *f, int a)
{
	char	*finish;
	char	*temp;
	char	*strnew;
	int		i;

	temp = NULL;
	strnew = ft_dup(str);
	i = f->pre;
	if (f->pre < a)
	{
		while (strnew[i] != '\0')
		{
			strnew[i] = '\0';
			i++;
		}
	}
	a = ft_strlen(strnew);
	if (f->champs > a)
		temp = ft_remp(f->champs - a);
	finish = ft_strjoin(temp, strnew);
	return (finish);
}

static	char		*ft_isfield(char *str, t_flags *f)
{
	char	*finish;
	char	*temp;
	char	*strnew;
	int		a;

	finish = NULL;
	temp = NULL;
	if (!(str))
		return (NULL);
	strnew = ft_dup(str);
	a = ft_strlen(strnew);
	if (f->champs > a)
		temp = ft_remp(f->champs - a);
	finish = ft_strjoin(temp, strnew);
	return (finish);
}

int					ft_string(char *str, t_flags *f, int a)
{
	char	*finish;

	if (f->pre == -1)
		finish = ft_isfield(str, f);
	if (f->pre == 0)
		finish = ft_remp(f->champs);
	if (f->pre > 0)
		finish = ft_str(str, f, a);
	if (!(f->attr))
	{
		ft_putstr(finish);
		f->count = ft_strlen(finish);
		ft_strdel(&finish);
		return (0);
	}
	if (f->attr[0] == '-' || f->attr[1] == '-')
		ft_minus(finish, f, a);
	ft_putstr(finish);
	f->count = ft_strlen(finish);
	ft_strdel(&finish);
	return (0);
}
