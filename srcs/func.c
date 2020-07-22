/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:20:29 by rlintill          #+#    #+#             */
/*   Updated: 2019/11/21 18:53:35 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_arrcmp(int *one, int *two, size_t n)
{
	unsigned	i;

	i = 0;
	if (n == 0)
		return (0);
	while (one[i] == two[i] && i < n - 1)
		i++;
	return (one[i] - two[i]);
}

int		check_tetr(int *arr)
{
	if (!ft_arrcmp(arr, I_P, 8) || !ft_arrcmp(arr, II_P, 8)
		|| !ft_arrcmp(arr, SQ_P, 8) || !ft_arrcmp(arr, L_P, 8)
		|| !ft_arrcmp(arr, LM_P, 8) || !ft_arrcmp(arr, G_P, 8)
		|| !ft_arrcmp(arr, GM_P, 8) || !ft_arrcmp(arr, GL_P, 8)
		|| !ft_arrcmp(arr, GLM_P, 8) || !ft_arrcmp(arr, GG_P, 8)
		|| !ft_arrcmp(arr, GGM_P, 8) || !ft_arrcmp(arr, S_P, 8)
		|| !ft_arrcmp(arr, SM_P, 8) || !ft_arrcmp(arr, E_P, 8)
		|| !ft_arrcmp(arr, ES_P, 8) || !ft_arrcmp(arr, T_P, 8)
		|| !ft_arrcmp(arr, TM_P, 8) || !ft_arrcmp(arr, TV_P, 8)
		|| !ft_arrcmp(arr, TVM_P, 8))
		return (0);
	return (1);
}

void	max_n_move(int **arr, int *x, int *y)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((*arr)[i] < *x && (i % 2 == 0))
			*x = (*arr)[i];
		if ((*arr)[i] < *y && (i % 2 != 0))
			*y = (*arr)[i];
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (*x != 0 && (i % 2 == 0))
			(*arr)[i]--;
		if (*y != 0 && (i % 2 != 0))
			(*arr)[i]--;
		i++;
	}
}

void	move(int **arr)
{
	int	i;
	int	x;
	int	y;
	int	t;

	t = 0;
	x = 4;
	y = 4;
	i = 0;
	while (t < 3)
	{
		max_n_move(arr, &x, &y);
		t++;
	}
}

int		coord(char **ln, int **tet, int *j, int *k)
{
	int	i;

	i = 0;
	while ((*ln)[i] != '\0')
	{
		if ((*ln)[i] == '#')
		{
			(*tet)[(*k)++] = i;
			(*tet)[(*k)++] = *j;
		}
		i++;
	}
	(*j)++;
	if ((*ln)[0] == '\0')
	{
		*j = 0;
		*k = 0;
		move(&(*tet));
		if (check_tetr(*tet))
			return (0);
	}
	return (1);
}
