/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/02 19:01:46 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

static void	static_introduction(t_parse *parse)
{
	unsigned int	i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < parse->n_champs)
	{
		ft_printf("* Player %u, weighing %u bytes, \"%s\" (\"%s\") !\n",
		parse->champs[i].id, parse->champs[i].code_size, parse->champs[i].name,
		parse->champs[i].comment);
		++i;
	}
}

int			main(int argc, char **argv)
{
	t_parse		parse;
	t_game_data	data;

	if (!corewar_parse(&parse, (unsigned int)argc, (const char **)argv))
	{
		ft_printf("Usage");
		return (0);
	}
	//TODO add switch to sdl2 visualisation
	static_introduction(&parse);
	corewar_game(&data, &parse);
	return (0);
}
# include "stdio.h"

void		corewar_dump(char *arena)
{
	unsigned int	i;

	i = 0;
	while (i < ARENA_SIZE)
	{
		if (arena[i] < 0)
		{
			arena[i] *= -1;
			write(1, "-", 1);
		}
		else
			write(1, " ", 1);
		if (arena[i] < 16)
			write(1, "0", 1);
		ft_printf("%x", arena[i] & 127);
		if (!((i + 1) % DUMP_LINE))
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		++i;
	}
}
