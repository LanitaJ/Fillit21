/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:51:37 by rlintill          #+#    #+#             */
/*   Updated: 2019/11/21 19:01:44 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*ft_strdup(const char *str)
{
	char	*nstr;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(str);
	nstr = (char*)malloc(sizeof(const char) * (l + 1));
	if (nstr == NULL)
		return (nstr);
	while (i < l)
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
