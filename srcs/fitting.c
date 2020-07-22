/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:55:29 by rlintill          #+#    #+#             */
/*   Updated: 2019/11/21 18:53:33 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	max(int z, t_tetr *fig)
{
	int	i;
	int	res;

	i = z;
	res = -1;
	while (i < 8)
	{
		if ((fig->tet_coor)[i] > res)
			res = (fig->tet_coor)[i];
		i += 2;
	}
	return (res);
}

int	isfitt(char **map, int fig[], t_point pnt)
{
	if (map[pnt.y + fig[1]][pnt.x + fig[0]] == '.'
		&& map[pnt.y + fig[3]][pnt.x + fig[2]] == '.'
		&& map[pnt.y + fig[5]][pnt.x + fig[4]] == '.'
		&& map[pnt.y + fig[7]][pnt.x + fig[6]] == '.')
	{
		return (1);
	}
	return (0);
}

int	place(char **map, t_tetr *fig, t_point pnt)
{
	map[pnt.y + (fig->tet_coor)[1]]
	[pnt.x + (fig->tet_coor)[0]] = fig->name_tet;
	map[pnt.y + (fig->tet_coor)[3]]
	[pnt.x + (fig->tet_coor)[2]] = fig->name_tet;
	map[pnt.y + (fig->tet_coor)[5]]
	[pnt.x + (fig->tet_coor)[4]] = fig->name_tet;
	map[pnt.y + (fig->tet_coor)[7]]
	[pnt.x + (fig->tet_coor)[6]] = fig->name_tet;
	return (1);
}

int	vstavkafigure(char **map, t_tetr *fig, short size, t_point pnt)
{
	int ymax;
	int xmax;

	ymax = max(1, fig);
	xmax = max(0, fig);
	while (pnt.y + ymax < size)
	{
		while (pnt.x + xmax < size)
		{
			if (isfitt(map, fig->tet_coor, pnt))
				return (place(map, fig, pnt));
			(pnt.x)++;
		}
		(pnt.y)++;
		pnt.x = 0;
	}
	return (0);
}
