/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:11:07 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/07 17:25:53 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		is_format(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||\
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||\
			c == 'c' || c == 'C' || c == 'e' || c == 'E' || c == 'f' || c == 'F' ||\
			c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == 'n');
}

char	*ft_strnchr(const char *s, int c, int size)
{
	while (c != *s && *s && size-- > 0)
		s++;
	if (c == *s)
		return ((char *)s);
	else
		return (NULL);
}

/*
int		d_format(const char *str, int index, int nbr)
{
	int		ct;
	char	*to_str;

	to_str = ft_itoa(nbr);
	ct = ft_strlen(to_str);
	ct = before_format(str, index, ct);
	return (ct);
}

int		before_format(const char *str, int index, int count)
{
	char	*s;
	int		i;
	int		width;

	i = 0;
}
*/

void	set_cast(t_data *fl, char *format, int size)
{
	int		i;

	i = 1;
	if (ft_strnstr(format, "hh", size))
		fl->cast = hh;
	else if(ft_strnstr(format, "ll",size))
		fl->cast = ll;
	else if(ft_strnchr(format, 'h',size))
		fl->cast = h;
	else if(ft_strnchr(format, 'l',size))
		fl->cast = l;
	else if(ft_strnchr(format, 'j',size))
		fl->cast = j;
	else if(ft_strnchr(format, 'z',size))
		fl->cast = z;
	else fl->cast = none;
}

int		nb_number(int number)
{
	int		i;

	i = 1;
	while (number > 9)
	{
		i++;
		number = number / 10;
	}
	return (i);
}

int		nb_digit(char *str)
{
	int		i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_putnstr(char const *s, int nbr)
{
	if (s)
	{
		while (*s && nbr-- >= 1)
			write(1, s++, 1);
	}
}

void	set_flags(t_data *fl, char *format, int size)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	//	fl->data = data;
	ft_bzero(fl->flags, 10);
	fl->width = 0;
	if (ft_strnchr(format, '.', size))
	fl->precison = 0;
	else
	fl->precison = ft_strlen(fl->ori);
	set_cast(fl, format, size);
	//ft_putendl("after .. is=");
	//ft_putnstr(format, size);
	while (i < size && j < 10)
	{
		//ft_putendl("enter or not 99999999999999999");
		if (format[i] == '0')
		{
			fl->flags[j++] = '0';
			i++;
		}
		else if ('0' < format[i] && format[i] <= '9')
		{
			fl->width = ft_atoi(format + i);
			//ft_putendl("width is =");
			//ft_putnbr(fl->width);
			i = i + nb_digit(format + 1);
		}
		else if (format[i] == '.')
		{
			if (format[i + 1] > '9' || format[i + 1] < '0')
				fl->precison = -1;
			else
				fl->precison = ft_atoi(format + 1 + i);
			i = i + nb_digit(format + 1) + 1;
		}
		else
		{
			if(ft_strchr("#-+ ", format[i]))
				fl->flags[j++] = format[i];
			i++;
		}
	}
}
/*
char	*get_data(va_list args, char c)
{
	char	*data;
	//	if (c == 's' || c == 'S')
}
*/

/*void	ini_set(t_fu **set)
{
	*set = {
		{'s',con_s},
		{'c',con_c},
		{'d',con_d},
	};
}
*/
/*
int		max(int x, int y, int z)
{
	int		max;

	max = x;
	if (y > max)
		max = y;
	if (z > max)
		max = z;
	return (z);
}
*/

int		max_2(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

void	ft_putnchar(char c, int nbr)
{
	while (nbr-- >= 1)
		write(1, &c, 1);
}

/*
void	buff_vide(char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
		str[i] = ' ';
}
*/

void	set_print_s(t_data *data)
{
	int		len;
//	char	buff[len + 1];

	len = max_2(data->width, ft_strlen(data->ori));
	//buff = ft_strnew(len + 1);
	//buff_vide(buff, len);
	if (data->precison == -1)
		data->precison = ft_strlen(data->ori);
	if (len == (int)ft_strlen(data->ori))
		ft_putstr(data->ori);
	else
	{
		if (ft_strchr(data->flags, '-'))
		{
			ft_putnstr(data->ori, data->precison);
			ft_putnchar(' ', data->width - data->precison);
		}
		else
		{
			ft_putnchar(' ', data->width - data->precison);
		ft_putnstr(data->ori, data->precison);
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		args;
	va_start(args, format);
	int			i;
	int			nbr;
	int			j;
	t_data		*data;
	//	char	*ori_data;
	t_fu	set[1] = {
		{'s',con_s},
	//	{'c',con_c},
	//	{'d',con_d},
	};

	nbr = 0;
	data = (t_data *)malloc(sizeof(*data));
	while (*format)
	{
		j = 0;
		i = 0;
		if( *format == '%')
		{
			while(format[i] && !is_format(format[i]))
				i++;
			while (j < NB_CON && set[j].c != format[i])
				j++;
			(set[j].func)(args, data, (char *)format, i);
			format = format + i + 1;
		}
		else
		ft_putchar(*format++);
		nbr++;
	}
	return (nbr);
}

int		main(void)
{
	ft_printf("nihao%6.2shaiyou%3s11111%s", "huhu", "dudu","kkkklastishere");
	return (0);
}
