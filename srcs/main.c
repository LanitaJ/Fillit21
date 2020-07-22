/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:54:28 by rlintill          #+#    #+#             */
/*   Updated: 2019/11/21 18:54:05 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	print_error(int fd)
{
	ft_putstr("error\n");
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_tetr	*tetr;
	int		fd;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (!valid(fd))
		return (print_error(fd));
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (!read_tetr(fd, &tetr))
		return (print_error(fd));
	close(fd);
	solve(tetr);
	del_tetr(&tetr);
	return (0);
}
