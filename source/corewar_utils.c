/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:17:04 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/17 20:54:42 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

int		corewar_8(int pos)
{
	pos %= ARENA_SIZE;
	if (pos < 0)
		pos += ARENA_SIZE;
	return (pos);
}

void	corewar_read_arg(t_data *data, unsigned int *value, unsigned char size,
		int pos)
{
	unsigned int	i;

	*value = 0;
	i = 0;
	while (i < size)
	{
		if (i)
			*value = *value << 8;
		*value = *value | data->arena[corewar_8(pos + i)];
		++i;
	}
}

void	corewar_write_arg(t_data *data, unsigned int value, unsigned char size,
		int pos)
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

void	corewar_kill_carrs(t_data *data, t_carriage *carr_tmp)
{
	t_carriage	*carr_prev;

	carr_prev = NULL;
	while (carr_tmp != NULL && data->carr->next)
	{
		if (data->ctc == 0 || carr_tmp->last_live < data->cycle - data->ctc)
		{
			if (carr_prev)
				carr_prev->next = carr_tmp->next;
			else
				data->carr = carr_tmp->next;
			ft_memdel((void**)&carr_tmp);
			if (carr_prev)
				carr_tmp = carr_prev->next;
			else
				carr_tmp = data->carr;
			data->n_carrs--;
		}
		else
		{
			carr_prev = carr_tmp;
			carr_tmp = carr_tmp->next;
		}
	}
}
