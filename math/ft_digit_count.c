/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:16:38 by hqixeo            #+#    #+#             */
/*   Updated: 2022/11/13 08:16:40 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit_count(size_t nbr)
{
	int	digit;

	digit = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		digit++;
	}
	return (digit);
}
