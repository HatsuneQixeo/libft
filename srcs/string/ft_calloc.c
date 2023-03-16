/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:32:04 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/16 09:26:44 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libstring.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*ptr;

	ptr = malloc(len * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, len * size);
	return (ptr);
}
