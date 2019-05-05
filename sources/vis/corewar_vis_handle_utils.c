/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_handle_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 23:48:36 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/05 23:49:43 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

void	corewar_vis_slowdown(t_vis *vis)
{
	if (vis->cycle_len < MAX_CYCLE_LEN)
		vis->cycle_len += DELTA_CYCLE_LEN;
}

void	corewar_vis_speedup(t_vis *vis)
{
	if (vis->cycle_len > 0)
		vis->cycle_len -= DELTA_CYCLE_LEN;
}
