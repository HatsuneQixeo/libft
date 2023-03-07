/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpis_str_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:52:42 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/07 15:22:12 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libstring.h"
#include "ft_printf.h"

int	cmp_strlesser(const void *str1, const void *str2)
{
	return (ft_strcmp(str1, str2));
}

int	cmp_strgreater(const void *str1, const void *str2)
{
	return (ft_strcmp(str2, str1));
}

int	cmp_strprefix(const void *str, const void *prefix)
{
	const char	*it_str = str;
	const char	*it_prefix = prefix;
	size_t		i;

	i = 0;
	if (str == NULL || prefix == NULL)
		return (0);
	while (it_str[i] == it_prefix[i] && it_str[i] != '\0')
		i++;
	if (it_prefix[i] == '\0')
		return (0);
	return (it_str[i] - it_prefix[i]);
}

int	cmp_strsuffix(const void *str, const void *suffix)
{
	const char	*it_str = str;
	const char	*it_suffix = suffix;
	size_t		len_str;
	size_t		len_suffix;

	len_str = ft_strlen(it_str);
	len_suffix = ft_strlen(it_suffix);
	while ((len_str-- != 0) + (len_suffix-- != 0) == 2)
	{
		if (it_str[len_str] != it_suffix[len_suffix])
			return (it_str[len_str] - it_suffix[len_suffix]);
	}
	if (len_str == SIZE_MAX && len_suffix != SIZE_MAX)
		return (-it_suffix[len_suffix]);
	return (0);
}
