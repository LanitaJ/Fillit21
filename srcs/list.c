/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:54:28 by rlintill          #+#    #+#             */
/*   Updated: 2019/11/21 18:53:56 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	arrmove(int *dst, int *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

int		count(t_tetr *tet)
{
	t_tetr	*tmp;
	int		n;

	tmp = tet;
	n = 0;
	if (tet)
		n = 1;
	while (tmp->next != NULL)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

t_tetr	*newtetr(int *coor, char name)
{
	t_tetr *tet;

	if (!(tet = (t_tetr*)malloc(sizeof(*tet))))
		return (NULL);
	if (!(tet->tet_coor = (int*)malloc(sizeof(coor) * 8)))
		return (NULL);
	arrmove(tet->tet_coor, coor, 8);
	tet->name_tet = name;
	tet->next = NULL;
	return (tet);
}

void	add_tail(t_tetr **head, int *tet_coor, char name_tet)
{
	t_tetr *tmp;

	tmp = NULL;
	if (*head == NULL)
	{
		tmp = newtetr(tet_coor, name_tet);
		*head = tmp;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = newtetr(tet_coor, name_tet);
}

t_point	to_null(void)
{
	t_point	pnt;

	pnt.x = 0;
	pnt.y = 0;
	return (pnt);
}
