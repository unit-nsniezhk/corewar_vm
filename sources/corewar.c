/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:22:00 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/03 00:00:57 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

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
	t_parse	parse;
	t_data	data;

	if (!corewar_parse(&parse, (unsigned int)argc, (const char **)argv))
	{
		ft_printf("Usage");
		return (0);
	}
	//TODO add switch to sdl2 visualisation
	static_introduction(&parse);
	corewar_vm(&data, &parse);
	return (0);
}
