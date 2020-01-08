/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:35:33 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:35:34 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_moins_espace(char *str, t_flags *f, int a)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = NULL;
	if (f->champs > f->pre && f->champs > a)
	{
		while (str[i] != ' ')
			i++;
		j = i - 1;
		while (i > 0)
		{
			str[i] = str[j];
			i--;
			j--;
		}
		str[i] = ' ';
		return (str);
	}
	else
		tmp = ft_strjoin(" ", str);
	return (tmp);
}

static	char	*ft_moins_plus(char *str, t_flags *f, int a)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = NULL;
	if (f->champs > f->pre && f->champs > a)
	{
		while (str[i] != ' ')
			i++;
		j = i - 1;
		while (i > 0)
		{
			str[i] = str[j];
			i--;
			j--;
		}
		str[i] = '+';
		return (str);
	}
	else
		tmp = ft_strjoin("+", str);
	return (tmp);
}

char			*ft_moins(char *str, t_flags *f, int a)
{
	int		i;
	int		j;
	int		c;
	char	*tmp;

	tmp = NULL;
	c = 0;
	j = 0;
	i = 0;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
		while (str[i] != '\0')
			str[j++] = str[i++];
		while (str[j] != '\0')
			str[j++] = ' ';
	}
	if (ft_strchr(f->attr, '+'))
		return (tmp = ft_moins_plus(str, f, a));
	else if (ft_strchr(f->attr, ' '))
		return (tmp = ft_moins_espace(str, f, a));
	return (str);
}
