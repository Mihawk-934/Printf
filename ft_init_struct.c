/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:35:00 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:35:01 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_struct(void)
{
	t_flags	f;

	f.attr = NULL;
	f.champs = 0;
	f.pre = -1;
	f.modif = NULL;
	f.conv = 0;
	f.count = 0;
	return (f);
}
