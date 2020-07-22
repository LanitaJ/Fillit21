/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrcking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:55:29 by rlintill          #+#    #+#             */
/*   Updated: 2019/11/21 18:53:27 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	printmap(char **map, short size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, map[i], size);
		write(1, "\n", 1);
		i++;
	}
}

char	**createmap(void)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (char**)malloc(sizeof(char*) * 17);
	while (i < 16)
	{
		map[i] = (char*)malloc(sizeof(char) * 17);
		j = 0;
		while (j < 16)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

int		replace(char **map, t_tetr *tet, short size, t_point *pnt)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (map[i][j] == tet->name_tet)
				map[i][j] = '.';
			i++;
		}
		j++;
	}
	if (pnt->x < size - 1)
		(pnt->x)++;
	else if (pnt->y < size - 1)
	{
		pnt->x = 0;
		(pnt->y)++;
	}
	return (backtracking(map, tet, size, *pnt));
}

int		backtracking(char **map, t_tetr *fig, short size, t_point pnt)
{
	short check;

	check = vstavkafigure(map, fig, size, pnt);
	if (fig->next)
	{
		if (!check)
			return (0);
		else if (backtracking(map, fig->next, size, to_null()))
			return (1);
		else
			return (replace(map, fig, size, &pnt));
	}
	else
	{
		if (check == 0)
			return (0);
		else
			return (1);
	}
}

void	solve(t_tetr *tet)
{
	short	size;
	short	cnt;
	char	**map;

	cnt = count(tet);
	size = 2;
	while (size * size < cnt * 4)
		size++;
	map = createmap();
	while (!(backtracking(map, tet, size, to_null())))
	{
		clear(map, size);
		size++;
	}
	printmap(map, size);
	delmap(map);
}
