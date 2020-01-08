/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:35:21 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:35:22 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base(size_t n, int base)
{
	int			a;
	size_t		b;
	char		*str;

	a = 2;
	b = n;
	while ((b /= base) >= 1)
		a++;
	if (!(str = (char*)malloc(sizeof(char) * a)))
		return (NULL);
	a--;
	str[a] = '\0';
	while (--a >= 0)
	{
		b = 48;
		if (n % base > 9)
			b = 87;
		str[a] = n % base + b;
		n = n / base;
	}
	return (str);
}
