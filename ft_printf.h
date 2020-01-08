/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclaude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:38:06 by miclaude          #+#    #+#             */
/*   Updated: 2019/12/15 16:38:07 by miclaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	char	*attr;
	int		champs;
	int		pre;
	char	*modif;
	char	conv;
	int		count;
}				t_flags;

int				ft_printf(const char *format, ...);
t_flags			ft_init_struct(void);

int				ft_modif_id2(va_list ap, t_flags *f);
int				ft_modif_id(va_list ap, t_flags *f);
int				ft_modif_oux2(va_list ap, t_flags *f);
int				ft_modif_oux(va_list ap, t_flags *f);
int				ft_modif_sc(va_list ap, t_flags *f);
int				ft_flag_zero(t_flags *f);
int				ft_point(va_list ap, t_flags *f);
int				ft_percen(t_flags *f);
char			*ft_moins(char *str, t_flags *f, int a);
int				ft_neg(char *str, t_flags *f);
char			*ft_chps_and_pre(char *str, t_flags *f);
int				ft_string(char *str, t_flags *f, int a);
char			*ft_remp0(int n);
char			*ft_remp(int n);
int				ft_attr_id(char *str, t_flags *f);
int				ft_attr_oux(char *str, t_flags *f);
void			ft_upper(char *str);
int				ft_conv(va_list ap, t_flags *f);
int				parse(const char *format, t_flags *f);
int				ft_d(va_list ap, t_flags *f);
int				ft_ou(va_list ap, t_flags *f);

char			*ft_strchr(const char *s, int c);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_isdigit(int c);
void			ft_strdel(char **as);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putnbr(int n);
int				ft_strlen(const char *s);
int				ft_atoi(const char *format);
int				ft_strnlen(const char *str, char c);
void			ft_putstr(const char *str);
char			*ft_itoa_base(size_t n, int base);
void			ft_putchar(char c);
#endif
