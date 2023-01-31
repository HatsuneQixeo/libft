/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:50:24 by hqixeo            #+#    #+#             */
/*   Updated: 2023/01/31 18:02:30 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

long	ft_min_long(long a, long b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

size_t	ft_min_sizet(size_t a, size_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}
