/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 15:37:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/10/10 15:45:46 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strjoin qui leaks pas bis
*/

char	*ft_strjoin_free2(char *dst, char *src)
{
	char	*tmp;

	if (!src)
		return (dst);
	if (!dst)
		return (src);
	tmp = ft_strdup(dst);
	dst = ft_strjoin(tmp, src);
	ft_strdel(&src);
	ft_strdel(&tmp);
	return (dst);
}
