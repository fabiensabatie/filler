/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:24:23 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/09 14:24:24 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_retsplit(char *str, char c, int n)
{
	char **tab;
	char *ret;
	int i;

	i = 0;
	tab = ft_strsplit(str, c);
	ret = ft_strdup(tab[n]);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	free(ret);
	return (ret);
}


