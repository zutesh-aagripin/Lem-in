/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:45:44 by aagripin          #+#    #+#             */
/*   Updated: 2020/02/03 12:30:13 by aagripin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	bubblesort(int *moves, t_path **way, int size)
{
	int		i;
	int		j;
	int		flag;
	t_path	*ptr;

	i = -1;
	flag = 1;
	while (++i < size && flag)
	{
		j = -1;
		flag = 0;
		while (++j < size - 1)
		{
			if (moves[j] > moves[j + 1])
			{
				flag = 1;
				ft_swap(&moves[j], &moves[j + 1]);
				ptr = way[j];
				way[j] = way[j + 1];
				way[j + 1] = ptr;
			}
		}
	}
}

void	move_ant(t_ant *ant, int i, char **names)
{
	if (ant[i].way != NULL)
	{
		ft_putchar('L');
		ft_putnbr(ant[i].num);
		ft_putchar('-');
		ft_putstr(names[ant[i].way->vert_num]);
		ft_putchar(' ');
		ant[i].way = ant[i].way->next;
		if (ant[i].way != NULL)
			ant[i].condition = 2;
		else if (ant[i].way == NULL)
			ant[i].condition = 3;
	}
	else
		ant[i].condition = 3;
}

int		move_ants_on_way(t_graph *graph, t_ant *ant, int *antsonway)
{
	int		i;

	i = -1;
	while (++i < graph->num_of_ants)
	{
		if (ant[i].condition == 2)
		{
			move_ant(ant, i, graph->names);
			if (ant[i].condition == 3)
				*antsonway -= 1;
		}
	}
	return (-1);
}

void	move_all_ants(t_graph *graph, t_path **ways, t_ant *ant,
int num_of_ways)
{
	int		ants_launched;
	int		antsonway;
	int		ways_used;
	int		i;

	ants_launched = 0;
	antsonway = 0;
	while (ants_launched < graph->num_of_ants || antsonway)
	{
		ways_used = move_ants_on_way(graph, ant, &antsonway);
		while (++ways_used < num_of_ways)
		{
			i = -1;
			while (++i < graph->num_of_ants)
				if (ant[i].condition == 1 && ant[i].way == ways[ways_used])
				{
					ant[i].num = ++ants_launched;
					move_ant(ant, i, graph->names);
					if (ant[i].condition == 2)
						antsonway++;
					break ;
				}
		}
		ft_putchar('\n');
	}
}

void	ft_output(t_path **ways, int num_of_ways, t_graph *graph)
{
	int		moves[num_of_ways];
	int		i;
	t_ant	ant[graph->num_of_ants];

	print_input_struct(graph->input);
	i = -1;
	while (++i < num_of_ways)
		moves[i] = calculate_moves(ways[i]);
	i = 0;
	bubblesort(moves, ways, num_of_ways);
	i = -1;
	while (++i < graph->num_of_ants)
	{
		ant[i].way = ways[0];
		ant[i].num = i + 1;
		ant[i].condition = 1;
		moves[0]++;
		bubblesort(moves, ways, num_of_ways);
	}
	move_all_ants(graph, ways, ant, num_of_ways);
}
