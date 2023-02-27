/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:22:16 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/27 10:59:57 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//Return 1 if filename end with given format
//Return 0 if filename does not end with given format
//and prints out an error message 
int	ft_file_format(const char *file, const char *format)
{
	if (ft_strcmp(file + (ft_strlen(file) - ft_strlen(format)), format))
		return (!ft_dprintf(2, "(%s) is not (%s) file\n", file, format));
	return (1);
}