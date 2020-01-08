/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:39:02 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:39:04 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_remp(int n)
{
	char	*str;

	str = NULL;
	if (n <= 0)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * n + 1)))
		return (NULL);
	str[n] = '\0';
	while (--n >= 0)
		str[n] = ' ';
	return (str);
}
