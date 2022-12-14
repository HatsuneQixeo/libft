/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprintable_sign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:18:04 by hqixeo            #+#    #+#             */
/*   Updated: 2022/11/13 08:18:10 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_setnpc_sign(char *str, unsigned char npc)
{
	*str++ = '\\';
	if (npc == '\b')
		*str = 'b';
	else if (npc == '\f')
		*str = 'f';
	else if (npc == '\n')
		*str = 'n';
	else if (npc == '\r')
		*str = 'r';
	else if (npc == '\t')
		*str = 't';
	else
		*str = '0';
	return (2);
}

//Undefined character are represent as '0'
char	*ft_strprintable_sign(const char *src)
{
	char	*str_main;
	char	*tmp;
	size_t	len_printable;

	len_printable = ft_strchr_countis(src, ft_isprint);
	str_main = malloc(len_printable + (ft_strlen(src) - len_printable) * 2 + 1);
	if (str_main == NULL)
		return (NULL);
	tmp = str_main;
	while (*src)
		if (ft_isprint(*src))
			*str_main++ = *src++;
	else
		str_main += ft_setnpc_sign(str_main, *src++);
	*str_main = '\0';
	return (tmp);
}
