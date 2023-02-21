/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_sucks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:04:01 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/19 19:06:19 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void	memset_sucks(unsigned int nbr, void *(set)(void *, int, size_t))
{
	unsigned int	*ptr;
	size_t			len;

	len = sizeof(int) * 10;
	ptr = malloc(len);
	ft_printf("nbr: %u\n", nbr);
	if (set == ft_memset)
		ft_printf("ft_");
	ft_printf("memset\n");
	set(ptr, len, sizeof(int));
	ft_memprint(ptr, len, sizeof(int));
	ft_printf("%u\n", *ptr);
}

int	main(void)
{
	memset_sucks(0xff0000fe, memset);
	memset_sucks(0xff0000fe, ft_memset);
}