/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:49:22 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/07 17:23:08 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft/libft.h"
#include "ft_printf.h"

static	int	nb_digit(intmax_t n)
{
	int i;
	uintmax_t nb;

	i = 1;
	if (n < 0)
	{
		i = 2;
		nb = (uintmax_t)n * -1;
	}
	else
		nb = (uintmax_t)n;
	while (nb > 9)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa_max(intmax_t n)
{
	char	*number;
	int		len;
	intmax_t	cp_n;

	len = nb_digit(n);
	if (!(number = (char *)malloc(len + 1)))
		return (NULL);
	number[len] = '\0';
	if (!n)
		number[0] = '0';
	if (n < 0)
	{
		number[0] = '-';
		cp_n = (uintmax_t)n * -1;
	}
	else
		cp_n = (uintmax_t)n;
	while (cp_n)
	{
		number[--len] = cp_n % 10 + '0';
		cp_n = cp_n / 10;
	}
	return (number);
}

void	con_s(va_list args, t_data *data, char *format, int size)
{
	data->ori = va_arg(args, char *);
	set_flags(data, format, size);
	set_print_s(data);
}

/*
void	con_c(va_list args, t_data *data, char *format, int size)
{
	data->ori = "va_arg(args, char)";
	set_flags(data, format, size);
}

void	con_d(va_list args, t_data *data, char *format, int size)
{
	int		nb;

	nb = va_arg(args, int);
	data->ori = ft_itoa_max(nb);
	set_flags(data, format, size);
}
*/

