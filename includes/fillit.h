/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:55:29 by rlintill          #+#    #+#             */
/*   Updated: 2019/11/21 19:02:18 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 4096
# define LINE_SIZE 4096
# define EOL_SYMB '\n'
# define EOF_SYMB '\0'

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define I_P (int[8]) {0, 0, 0, 1, 0, 2, 0, 3}
# define II_P (int[8]) {0, 0, 1, 0, 2, 0, 3, 0}
# define SQ_P (int[8]) {0, 0, 1, 0, 0, 1, 1, 1}
# define L_P (int[8]) {0, 0, 0, 1, 0, 2, 1, 2}
# define LM_P (int[8]) {1, 0, 1, 1, 0, 2, 1, 2}
# define G_P (int[8]) {0, 0, 1, 0, 0, 1, 0, 2}
# define GM_P (int[8]) {0, 0, 1, 0, 1, 1, 1, 2}
# define GL_P (int[8]) {2, 0, 0, 1, 1, 1, 2, 1}
# define GLM_P (int[8]) {0, 0, 0, 1, 1, 1, 2, 1}
# define GG_P (int[8]) {0, 0, 1, 0, 2, 0, 0, 1}
# define GGM_P (int[8]) {0, 0, 1, 0, 2, 0, 2, 1}
# define S_P (int[8]) {0, 0, 0, 1, 1, 1, 1, 2}
# define SM_P (int[8]) {1, 0, 0, 1, 1, 1, 0, 2}
# define E_P (int[8]) {0, 0, 1, 0, 1, 1, 2, 1}
# define ES_P (int[8]) {1, 0, 2, 0, 0, 1, 1, 1}
# define T_P (int[8]) {0, 0, 1, 0, 2, 0, 1, 1}
# define TM_P (int[8]) {1, 0, 0, 1, 1, 1, 2, 1}
# define TV_P (int[8]) {0, 0, 0, 1, 1, 1, 0, 2}
# define TVM_P	(int[8]) {1, 0, 0, 1, 1, 1, 1, 2}

typedef struct		s_tetr
{
	int				*tet_coor;
	char			name_tet;
	struct s_tetr	*next;
}					t_tetr;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

void				add_tail(t_tetr **head, int *tet_coor, char name_tet);
void				arrmove(int *dst, int *src, size_t n);
t_tetr				*newtetr(int *coor, char name);
int					ft_arrcmp(int *one, int *two, size_t n);
int					check_tetr(int *arr);
void				move(int **arr);
int					read_tetr(int fd, t_tetr **tetr);
int					valid(int fd);
void				del_tetr(t_tetr **t);
int					coord(char **ln, int **tet, int *j, int *k);
void				max_n_move(int **arr, int *x, int *y);
void				solve(t_tetr *tet);
int					vstavkafigure(char **map,
									t_tetr *fig, short size, t_point pnt);
int					isfitt(char **map, int fig[], t_point pnt);
int					max(int z, t_tetr *fig);
int					replace(char **map, t_tetr *tet, short size, t_point *pnt);
int					count(t_tetr *tet);
int					backtracking(char **map,
									t_tetr *fig, short size, t_point pnt);
char				**createmap(void);
t_point				to_null(void);
int					place(char **map, t_tetr *fig, t_point pnt);
int					valid_by_tet(char *ln, int *d, int *h, int k);
int					end_of_tetr(char **ln, int *d, int *h, int *k);
int					print_error(int fd);
void				clear(char **map, int size);
void				printmap(char **map, short size);
void				ft_delarr(int **ap);
void				delmap(char **map);

int					get_next_line(const int fd, char **line);

char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_strdel(char **as);
char				*ft_strchr(const char *str, int symb);
void				ft_putstr(char const *s);
void				ft_putchar(char c);

#endif
