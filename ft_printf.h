/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:54:36 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/07 17:23:04 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdint.h>
#include <stdarg.h>

#define is_hash(x) ((x == '#')? 1 : 0)
#define is_zero(x) ((x == '0')? 1 : 0)
#define is_minus(x) ((x == '-')? 1 : 0)
#define is_plus(x) ((x == '+')? 1 : 0)
//#define is_width(x) x
//#define is_precison(x) x
#define is_end(x) ((x == '\0')? 1 : 0)

//#define is_hh(x) ((x == '#')? 1 : 0)
//#define is_h(x) ((x == 'h')? 1 : 0)
//#define is_l(x) ((x == 'l')? 1 : 0)
//#define is_ll(x) ((x == "ll")? 1 : 0)
//#define is_j(x) ((x == 'j')? 1 : 0)
//#define is_z(x) ((x == 'z')? 1 : 0)
//#define is_star(x) ((x == '*')? 1 : 0)
//#define is_dollar(x) ((x == '$')? 1 : 0)
//#define is_L(x) ((x == 'L')? 1 : 0)
//#define is_dot(x) ((x == ''')? 1 : 0)
typedef enum	s_cast
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
}		t_cast;

typedef	struct	s_data
{
	char	*ori;
	char	flags[10];
	int		width;
	int		precison;
	t_cast	cast;
//	is_hh;
//	is_h;
//	is_l;
//	is_ll;
//	is_j;
//	is_z;
//	is_star;
//	is_dollar;
//	is_L;
//	is_dot;
}			t_data;

#define NB_CON	16

typedef struct s_fu
{
	char	c;

	void (*func)(va_list, t_data *, char *, int);
}				t_fu;


void	con_s(va_list args, t_data *data, char *foamat, int size);
void	set_flags(t_data *fl, char *format, int size);
void	set_print_s(t_data *data);


#endif
