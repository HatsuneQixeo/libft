/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:04:44 by hqixeo            #+#    #+#             */
/*   Updated: 2022/08/04 11:04:45 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_printwidth(char c, int width, int fd)
{
	return (ft_strrelease_fd(ft_strcreate(c, width), fd));
}

static int	ft_character(char c, t_flags *flags)
{
	if (!flags->width || flags->width == 1)
		return (ft_putchar_fd(c, flags->fd));
	else if (flags->negative_field)
		return (ft_putchar_fd(c, flags->fd)
			+ ft_printwidth(' ', flags->width - 1, flags->fd));
	else if (flags->zero)
		return (ft_printwidth('0', flags->width - 1, flags->fd)
			+ ft_putchar_fd(c, flags->fd));
	else
		return (ft_printwidth(' ', flags->width - 1, flags->fd)
			+ ft_putchar_fd(c, flags->fd));
}

int	ft_conversion(va_list args, t_flags *flags)
{
	char	*str;

	if (flags->format == 's' || flags->format == 'b')
		str = ft_strdup(va_arg(args, char *));
	else if (flags->format == 'd' || flags->format == 'i')
		str = ft_decimal(va_arg(args, long long), flags);
	else if (flags->format == 'p')
		str = ft_strmodify(ft_utoa_base(va_arg(args, uintptr_t), HEXADECIMAL),
				"0x", ft_strrjoin);
	else if (flags->format == 'u' || flags->format == 'o'
		|| flags->format == 'x' || flags->format == 'X')
		str = ft_unsigned(va_arg(args, unsigned long long), flags);
	else if (flags->format == 'c')
		return (ft_character(va_arg(args, int), flags));
	else if (flags->format)
		return (ft_character(flags->format, flags));
	else
		return (0);
	if (str == NULL)
		str = ft_strdup("(null)");
	return (ft_strrelease_fd(ft_strfinalize(str, flags), flags->fd));
}
