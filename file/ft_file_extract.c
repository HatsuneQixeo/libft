/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:16:34 by hqixeo            #+#    #+#             */
/*   Updated: 2022/11/13 08:16:36 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_file_extract(int fd)
{
	char	*str;
	char	*read;

	str = 0;
	read = get_next_line(fd);
	while (read)
	{
		str = ft_strcombine(str, read);
		read = get_next_line(fd);
	}
	return (str);
}
