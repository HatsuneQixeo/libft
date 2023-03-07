/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:04:01 by hqixeo            #+#    #+#             */
/*   Updated: 2023/03/07 15:22:10 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define TESTSTR	"Not 'str'string''string'ing'"
#define TESTRM	"'string'"

char	*strmod_rmsubstr(const char *str, const char *str_rm);

int	main(void)
{
	char	*str;

	str = strmod_rmsubstr(TESTSTR, TESTRM);
	printf("str: %s\n", str);
	free(str);
}
