/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:47:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 15:03:41 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

char			*ft_strcpy(char *dst, const char *src)
{
	char		*start;

	start = dst;
	while ((*dst++ = *src++))
		;
	GIMME(start);
}
