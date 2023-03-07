/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:54:36 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/07 15:22:09 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

union u_Fint
{
	float	f;
	int		i;
};

#define U_FINT_SIZE	sizeof(union u_Fint)

int	main(void)
{
	union u_Fint	flint;

	flint.f = 0;
	while ((flint.f += 0.1f) < 100)
	{
		printf("X:[%-9x] : F[%-9f]\n", flint.i, flint.f);
		ft_memprint(&flint, U_FINT_SIZE, U_FINT_SIZE);

		int	cast = flint.f;

		printf("Casting:[%-8d]\n", cast);
		ft_memprint(&cast, sizeof(int), sizeof(int));
		printf("\n");
		usleep(0.1 * (1000 * 1000));
	}
}
