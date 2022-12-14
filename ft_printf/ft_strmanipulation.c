/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmanipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:05:33 by hqixeo            #+#    #+#             */
/*   Updated: 2022/08/04 11:05:34 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

//This is sufficient for this project
//, since you are doing precision before any other padding
static int	ft_findsign(const char *str)
{
	if (ft_strchr("-+ ", *str))
		return (1);
	else if (!ft_strncmp(str, "0x", 2) || !ft_strncmp(str, "0X", 2))
		return (2);
	else
		return (0);
}

// static int	ft_findsign(char *str)
// {
// 	if (ft_strchr(str, '-') || ft_strchr(str, '+') || ft_strchr(str, ' '))
// 		return (1);
// 	else if (ft_strstr(str, "0x") || ft_strstr(str, "0X"))
// 		return (2);
// 	else
// 		return (0);
// }

static char	*ft_period(char *str, t_flags *flags)
{
	int	len_pad;
	int	sign;

	if (flags->format == 's' || flags->format == 'b')
	{
		if ((int)ft_strlen(str) > flags->precision)
			str[flags->precision] = '\0';
		return (str);
	}
	sign = ft_findsign(str);
	if (flags->precision == 0 && !ft_strcmp(&str[sign], "0")
		&& !(flags->format == 'o' && flags->sharp))
		str[sign] = '\0';
	len_pad = flags->precision + sign - ft_strlen(str);
	if (len_pad <= 0)
		return (str);
	return (ft_strcombine(ft_strcreate('0', len_pad), str));
}

static char	*ft_setsign(char *str, t_flags *flags)
{
	char	*c_set;
	char	*c_sign;

	if (flags->format == 'u' || flags->format == 'o'
		|| flags->format == 's' || flags->format == 'b')
		return (str);
	c_set = ft_strskipchr(str, ' ');
	c_sign = ft_strskipchr(c_set, '0');
	if (*c_sign == '-' || *c_sign == '+'
		|| (*c_sign == ' ' && ft_isdigit(*(c_sign + 1))))
		ft_swapchar(c_set, c_sign);
	else if (*c_sign == 'x' || *c_sign == 'X')
		ft_swapchar(++c_set, c_sign);
	return (str);
}

char	*ft_strfinalize(char *str, t_flags *flags)
{
	int	len_pad;

	if (flags->period)
		str = ft_period(str, flags);
	if (flags->format == 'b')
		str = ft_strmodify(str, HEXADECIMAL, ft_strprintable);
	len_pad = flags->width - ft_strlen(str);
	if (len_pad <= 0)
		return (ft_setsign(str, flags));
	else if (flags->negative_field)
		str = ft_strcombine(str, ft_strcreate(' ', len_pad));
	else if (flags->zero && !flags->period)
		str = ft_strcombine(ft_strcreate('0', len_pad), str);
	else if (flags->width)
		str = ft_strcombine(ft_strcreate(' ', len_pad), str);
	return (ft_setsign(str, flags));
}
