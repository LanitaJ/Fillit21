/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:53:45 by rlintill          #+#    #+#             */
/*   Updated: 2019/11/21 18:54:10 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		read_tetr(int fd, t_tetr **tetr)
{
	char	*ln;
	int		*tet;
	int		j;
	int		k;
	char	t;

	t = 'A';
	k = 0;
	j = 0;
	tet = (int*)malloc(sizeof(int) * 8);
	while (get_next_line(fd, &ln))
	{
		if (!coord(&ln, &tet, &j, &k))
			return (0);
		if (ln[0] == '\0')
			add_tail(tetr, tet, t++);
		free(ln);
	}
	move(&tet);
	if (check_tetr(tet))
		return (0);
	add_tail(tetr, tet, t);
	free(tet);
	return (1);
}

int		end_of_tetr(char **ln, int *d, int *h, int *k)
{
	if (((*ln)[0]) == '\0')
	{
		if (*d == 0 && *h == 0)
		{
			*d = 12;
			*h = 4;
			(*k)++;
		}
		else
		{
			free(*ln);
			return (0);
		}
	}
	return (1);
}

int		valid_by_tet(char *ln, int *d, int *h, int k)
{
	int	i;

	i = 0;
	while (ln[i] != '\0')
	{
		if (ln[i] != '.' && ln[i] != '#')
			return (0);
		if (ln[i] == '.')
			(*d)--;
		if (ln[i] == '#')
			(*h)--;
		if (*d < 0 || *h < 0 || k > 25)
			return (0);
		i++;
	}
	if (ln[i] == '\0' && i != 4 && i != 0)
		return (0);
	return (1);
}

int		valid(int fd)
{
	char	*ln;
	int		i;
	int		d;
	int		h;
	int		k;

	h = 4;
	d = 12;
	k = 0;
	while (get_next_line(fd, &ln))
	{
		i = 0;
		if (!(end_of_tetr(&ln, &d, &h, &k)))
			return (0);
		if (!(valid_by_tet(ln, &d, &h, k)))
		{
			free(ln);
			return (0);
		}
		free(ln);
	}
	if (d != 0 || h != 0)
		return (0);
	return (1);
}
