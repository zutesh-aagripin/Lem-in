/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:15:43 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 22:17:00 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <unistd.h>

# define NONE		0
# define START		1
# define FINISH		2
# define INF		1000000000

typedef struct		s_alg
{
	char			*name;
	int				num;
	struct s_verts	*next;
}					t_alg;

typedef struct		s_verts
{
	char			*name;
	int				num;
	struct s_verts	*next;
}					t_verts;

typedef struct		s_edges
{
	int				from;
	int				to;
	struct s_edges	*next;
}					t_edges;

typedef struct		s_path
{
	int				vert_num;
	struct s_path	*next;
}					t_path;

typedef struct		s_graph
{
	struct s_verts	*verts;
	char			**matrix;
	char			**names;
	struct s_edges	*edges;
	int				num_of_rooms;
	int				num_of_ants;
	int				start;
	int				finish;
	struct s_input	*input;
}					t_graph;

typedef struct		s_input
{
	char			*line;
	struct s_input	*next;
}					t_input;

typedef struct		s_ant
{
	int				num;
	char			condition;
	struct s_path	*way;
}					t_ant;

void				print_matrix(char **m_list, int len);
int					ford(char *occ, int *dist, int *prev, t_graph *graph);
int					reverse_ford(char *occ, int *dist, int *prev,
t_graph *graph);
void				algorithm(t_graph *graph);
void				ft_output(t_path **ways, int num_of_ways, t_graph *graph);
int					calculate_moves(t_path *way);
void				bubblesort(int *moves, t_path **way, int size);
void				move_ant(t_ant *ant, int i, char **names);
int					move_ants_on_way(t_graph *graph, t_ant *ant,
int *antsonway);
void				move_all_ants(t_graph *graph, t_path **ways, t_ant *ant,
int num_of_ways);
t_graph				*read_input(void);
int					is_it_a_room(t_graph *graph, char *line, char *marker,
int num_room);
int					is_it_a_link(t_graph *graph, char *line);
void				free_names(char ***names);
char				**make_names(t_verts *verts);
void				free_matrix(char ***matrix, int num_of_rooms);
void				make_matrix(t_graph *graph);
void				free_edges(t_edges **edges);
void				push_edges_front(t_edges **edges, int first, int second);
int					edges_is_dublicated(t_edges *edges, int first, int second);
void				free_verts(t_verts **first);
void				push_vert_front(t_verts **first, char *str);
int					room_is_dublicated(t_verts *last, char *room);
t_verts				*find_vert(t_verts *first, char *str);
void				free_graph(t_graph **graph);
t_graph				*init_graph(char *line);
t_path				*restore_path(char *occ, int *prev, int path_num,
t_graph *graph);
void				free_paths(t_path **paths, int num_of_paths);
void				push_line_back(t_input *first_line, char *new_line);
void				free_input_struct(t_input **first_line);
void				print_input_struct(t_input *first_line);

#endif
