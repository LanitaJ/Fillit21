/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:13:02 by rlintill          #+#    #+#             */
/*   Updated: 2019/11/21 18:53:30 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_delarr(int **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	del_tetr(t_tetr **t)
{
	if (!(*t))
		return ;
	ft_delarr(&(*t)->tet_coor);
	if ((*t)->next != NULL)
		del_tetr(&(*t)->next);
	free(*t);
}

void	clear(char **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	delmap(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
