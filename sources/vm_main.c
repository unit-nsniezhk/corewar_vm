/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/01 17:15:53 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vm.h"

int		main(int argc, char **argv)
{
	t_parse		parse;
	t_game_data	data;

	if (!corewar_parse(&parse, (unsigned int)argc, (const char **)argv))
	{
		ft_printf("Usage");
		return (0);
	}
	//TODO add switch to sdl2 visualisation
	corewar_game(&data, &parse);
	return (0);
}

void	corewar_dump(unsigned char *arena)
{
	unsigned int	i;

	i = 0;
	while (i < ARENA_SIZE)
	{
		if (arena[i] < 16)
			ft_printf("0");
		ft_printf("%x", (unsigned int)arena[i]);
		if (!(i % DUMP_LINE))
			ft_printf("\n");
		else
			ft_printf(" ");
		++i;
	}
}
