/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:08:15 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/07 15:22:14 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libstring.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	len;
	size_t	len_to_find;

	if (str == NULL || to_find == NULL)
		return (NULL);
	else if (*to_find == '\0')
		return ((char *)str);
	len = ft_strlen(str);
	len_to_find = ft_strlen(to_find);
	while (*str != '\0' && len-- >= len_to_find)
		if (!ft_strncmp(str++, to_find, len_to_find))
			return ((char *)--str);
	return (NULL);
}
