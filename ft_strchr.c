/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:39:28 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:39:29 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned	char	o;
	int					i;

	i = 0;
	o = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != o)
		i++;
	if (o == '\0')
		return ((char*)s + i);
	if (s[i] == '\0')
		return (NULL);
	return ((char*)s + i);
}
