/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagextract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:05:19 by hqixeo            #+#    #+#             */
/*   Updated: 2022/12/22 00:17:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	flags_init(t_flags *flags)
{
	flags->format = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->mod_long = 0;
	flags->mod_short = 0;
	flags->mod_z = 0;
	flags->negative_field = 0;
	flags->zero = 0;
	flags->period = 0;
	flags->width = 0;
	flags->precision = 0;
}

static int	ft_atoflag(const char **str, char *flag, int saved, va_list args)
{
	int	value;

	value = 0;
	if (flag != NULL)
		*flag = 1;
	if (*++(*str) == '*')
		return (va_arg(args, int));
	while (ft_isdigit(**str))
		value = (value * 10) + (*(*str)++ - '0');
	(*str)--;
	if (value == 0)
		return (saved);
	return (value);
}

static void	ft_width(const char **str, t_flags *flags, va_list args)
{
	if (**str == '-')
		flags->negative_field = 1;
	else if (**str == '0')
		flags->zero = 1;
	else if (ft_isdigit(**str) || **str == '*')
		(*str)--;
	else
		return ;
	flags->width = ft_atoflag(str, NULL, flags->width, args);
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->negative_field = 1;
	}
}

static void	ft_length_modifier(char c, t_flags *flags)
{
	if (c == 'z')
		flags->mod_z = 1;
	else if (c == 'l')
		flags->mod_long += 1;
	else if (c == 'h')
		flags->mod_short += 1;
}

char	*ft_flagextract(const char *str, t_flags *flags, va_list args)
{
	flags_init(flags);
	while (*++str != '\0'
		&& (ft_strchr("-+ #.*,;:_zlh", *str) || ft_isdigit(*str)))
	{
		if (*str == '#')
			flags->sharp = 1;
		else if (*str == '+')
			flags->plus = 1;
		else if (*str == ' ')
			flags->space = 1;
		else if (ft_strchr("zlh", *str))
			ft_length_modifier(*str, flags);
		else if (*str == '.')
			flags->precision = ft_atoflag(&str, &flags->period, 0, args);
		else
			ft_width(&str, flags, args);
	}
	if (flags->precision < 0)
	{
		flags->period = 0;
		flags->precision = 0;
	}
	flags->format = *str;
	return ((char *)str);
}

//An alternative of atoflag with 2 separate function
// static int atoflag_core(const char **str)
// {
// 	const char	*str_tmp;
// 	int			value;

// 	value = 0;
// 	str_tmp = *str;
// 	while (ft_isdigit(*str_tmp))
// 		value = (value * 10) + (*str_tmp++ - '0');
// 	*str = --str_tmp;
// 	return (value);
// }

// static int ft_atoflag(const char **str, char *flag, int saved, va_list args)
// {
// 	int	value;

// 	if (flag)
// 		*flag = 1;
// 	if (*(++*str) == '*')
// 		return (va_arg(args, int));
// 	value = atoflag_core(str);
// 	if (value)
// 		return (value);
// 	else
// 		return (saved);
// }
