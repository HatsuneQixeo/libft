/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libalgo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:52:49 by hqixeo            #+#    #+#             */
/*   Updated: 2023/02/27 11:00:02 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBALGO_H
# define LIBALGO_H

# include "libis.h"
# include <stdlib.h>

typedef const char	*(*t_ftsetname)(const char *name);
typedef void		(*t_ftiteri)(unsigned int i, void *content);
typedef void		*(*t_ftmap)(void *content);
typedef void		(*t_ftdel)(void *content);

const char	*iteri_name(const char *newname);
void		iteri_putendl(unsigned int i, void *p_str);
void		iteri_showstr(unsigned int i, void *p_str);
void		iteri_showaddress(unsigned int i, void *p_ptr);

void		*map_copy(void *content);
void		*map_strdup(void *content);

typedef int			(*t_ftfind)(unsigned int i, const void *arr,
			const void *ref);

#endif