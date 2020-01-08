/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:36:50 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:36:51 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_minus(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
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
	return (str);
}

static	char	*ft_is_zero(char *str, t_flags *f)
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

static	char	*ft_is_plus(char *str, t_flags *f, int a)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (f->pre >= f->champs)
	{
		temp = ft_strjoin("-", str);
		return (temp);
	}
	if (!(ft_strchr(f->attr, '-')))
		if (ft_strchr(f->attr, '0'))
			str = ft_is_zero(str, f);
	while (str[i] == ' ')
		i++;
	if (i != 0)
		str[i - 1] = '-';
	else if (f->champs > a)
		str[i] = '-';
	else
	{
		temp = ft_strjoin("-", str);
		return (temp);
	}
	return (str);
}

int				ft_neg(char *str, t_flags *f)
{
	char	*finish;
	char	*strattr;
	int		a;

	a = 0;
	finish = NULL;
	strattr = NULL;
	a = ft_strlen(str);
	strattr = ft_chps_and_pre(str, f);
	finish = ft_is_plus(strattr, f, a);
	if (ft_strchr(f->attr, '-'))
		finish = ft_minus(finish);
	ft_putstr(finish);
	f->count = ft_strlen(finish);
	return (0);
}
