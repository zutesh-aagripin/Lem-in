/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:59:36 by cmissy            #+#    #+#             */
/*   Updated: 2020/01/31 14:08:15 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		print_input_struct(t_input *first_line)
{
	t_input		*tmp;

	tmp = first_line;
	while (tmp)
	{
		write(1, tmp->line, ft_strlen(tmp->line));
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void		free_input_struct(t_input **first_line)
{
	t_input		*input_list;
	t_input		*tmp;

	input_list = *first_line;
	while (input_list)
	{
		tmp = input_list->next;
		free(input_list->line);
		free(input_list);
		input_list = tmp;
	}
	*first_line = NULL;
}

void		push_line_back(t_input *first_line, char *new_line)
{
	t_input		*tmp;

	tmp = first_line;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(t_input))))
		exit(1);
	tmp->next->line = new_line;
	tmp->next->next = NULL;
}
