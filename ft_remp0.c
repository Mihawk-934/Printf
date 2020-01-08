/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:39:13 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:39:14 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_remp0(int n)
{
	char	*str;

	str = NULL;
	if (!(str = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	str[n] = '\0';
	while (--n >= 0)
		str[n] = '0';
	return (str);
}
