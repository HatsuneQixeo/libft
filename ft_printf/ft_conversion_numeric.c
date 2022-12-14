/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:49:44 by hqixeo            #+#    #+#             */
/*   Updated: 2022/11/13 13:49:46 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static unsigned long long	ft_ulength(unsigned long long nbr, t_flags *flags)
{
	if (flags->mod_z)
		return ((size_t)nbr);
	else if (flags->mod_long % 2)
		return ((unsigned long)nbr);
	else if (flags->mod_long)
		return ((unsigned long long)nbr);
	else if (flags->mod_short % 2)
		return ((unsigned short)nbr);
	else if (flags->mod_short)
		return ((unsigned char)nbr);
	else
		return ((unsigned int)nbr);
}

static long long	ft_dlength(long long nbr, t_flags *flags)
{
	if (flags->mod_long % 2)
		return ((long)nbr);
	else if (flags->mod_long)
		return ((long long)nbr);
	else if (flags->mod_short % 2)
		return ((short)nbr);
	else if (flags->mod_short)
		return ((char)nbr);
	else
		return ((int)nbr);
}

char	*ft_decimal(long long d, t_flags *flags)
{
	char	*nbr;

	d = ft_dlength(d, flags);
	nbr = ft_lltoa(d);
	if (d < 0)
		return (nbr);
	else if (flags->plus)
		return (ft_strmodify(nbr, "+", ft_strrjoin));
	else if (flags->space)
		return (ft_strmodify(nbr, " ", ft_strrjoin));
	else
		return (nbr);
}

char	*ft_unsigned(unsigned long long hex, t_flags *flags)
{
	char	*str;

	hex = ft_ulength(hex, flags);
	if (flags->format == 'u')
		return (ft_utoa_base(hex, DECIMAL));
	else if (flags->format == 'x')
		str = ft_utoa_base(hex, HEXADECIMAL);
	else if (flags->format == 'X')
		str = ft_utoa_base(hex, UPPERHEX);
	else if (flags->format == 'o')
		str = ft_utoa_base(hex, OCTAL);
	else
		return (0);
	if (*str == '0' || !flags->sharp)
		return (str);
	else if (flags->format == 'x')
		return (ft_strmodify(str, "0x", ft_strrjoin));
	else if (flags->format == 'X')
		return (ft_strmodify(str, "0X", ft_strrjoin));
	else if (flags->format == 'o')
		return (ft_strmodify(str, "0", ft_strrjoin));
	return (str);
}
