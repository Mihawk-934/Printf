/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attr_oux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:34:21 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:34:23 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_zzero(char *str, t_flags *f)
{
	int		i;

	i = 0;
	if (f->pre != -1)
		return ;
	while (str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	if (ft_strchr(f->attr, '#'))
	{
		while (str[i] != 'x')
			i++;
		str[i] = '0';
		str[1] = 'x';
	}
}

static	char	*ft_htag2(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	if (str[0] != ' ')
	{
		temp = ft_strjoin("0x", str);
		ft_strdel(&str);
		return (temp);
	}
	while (str[i] == ' ')
		i++;
	if (i > 1)
	{
		str[i - 1] = 'x';
		str[i - 2] = '0';
		return (str);
	}
	str[i - 1] = 'x';
	temp = ft_strjoin("0", str);
	ft_strdel(&str);
	return (temp);
}

static	char	*ft_htag(char *str, t_flags *f, int a)
{
	int		i;
	char	*temp;

	temp = NULL;
	i = 0;
	if (f->conv == 'o' || f->conv == 'O')
	{
		if (a >= f->champs && a >= f->pre)
		{
			temp = ft_strjoin("0", str);
			return (temp);
		}
		if (f->pre > a)
			return (str);
		str[f->champs - a - 1] = '0';
		return (str);
	}
	if ((f->conv == 'x' || f->conv == 'X'))
	{
		temp = ft_htag2(str);
		return (temp);
	}
	ft_strdel(&str);
	return (temp);
}

static	char	*ft_minus(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str)
	{
		if (str[i] != ' ')
			return (str);
		while (str[i] == ' ')
			i++;
		while (str[i] != '\0')
		{
			str[j] = str[i];
			j++;
			i++;
		}
		while (str[j] != '\0')
		{
			str[j] = ' ';
			j++;
		}
	}
	return (str);
}

int				ft_attr_oux(char *str, t_flags *f)
{
	char	*finish;
	char	*temp;
	int		a;

	a = ft_strlen(str);
	temp = NULL;
	finish = NULL;
	finish = ft_chps_and_pre(str, f);
	if (ft_strchr(f->attr, '#'))
		temp = ft_htag(finish, f, a);
	else
		temp = finish;
	if (ft_strchr(f->attr, '-'))
		ft_minus(temp);
	if (ft_strchr(f->attr, '0'))
		ft_zzero(temp, f);
	if (f->conv == 'O' || f->conv == 'X')
		ft_upper(temp);
	ft_putstr(temp);
	f->count = ft_strlen(temp) + f->count;
	ft_strdel(&temp);
	return (0);
}
