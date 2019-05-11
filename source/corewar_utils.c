/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:17:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/03 18:49:20 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_8(int pos)
{
	pos %= ARENA_SIZE;
	if (pos < 0)
		pos += ARENA_SIZE;
	return (pos);
}

void	corewar_read_arg(t_data *data, int *value, unsigned char size, int pos)
{
	unsigned int	i;

	*value = 0;
	i = 0;
	while (i < size)
	{
		if (i)
			*value = *value << 8;
		*value = *value | (char)(data->arena[corewar_8(pos + i)]);
		++i;
	}
}

void	corewar_write_arg(t_data *data, int value, unsigned char size, int pos)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		data->arena[corewar_8(pos + i)] =
				(unsigned char)(value >> (8 * (size - i - 1)));
		++i;
	}
}
