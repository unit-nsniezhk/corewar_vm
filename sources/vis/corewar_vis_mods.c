/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_mods.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:40:21 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 21:57:56 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis_def.h"

void	corewar_vis_speed(t_vis *vis, unsigned int state)
{
	if (state)
	{
		if (vis->cycle_ms > MIN_CYCLE_MS)
			vis->cycle_ms -= D_CYCLE_MS;
	}
	else
	{
		if (vis->cycle_ms < MAX_CYCLE_MS)
			vis->cycle_ms += D_CYCLE_MS;
	}
}

void	corewar_vis_run(t_vis *vis)
{
	if (vis->buttons.pause.state)
	{
		vis->buttons.pause.state = 0;
		vis->buttons.status.state = 0;
	}
	else
	{
		vis->buttons.pause.state = 1;
		vis->buttons.status.state = 1;
		vis->buttons.values.state = 0;
	}
}

void	corewar_vis_values(t_vis *vis)
{
	if (vis->buttons.values.state)
		vis->buttons.values.state = 0;
	else
	{
		vis->buttons.values.state = 1;
		vis->buttons.pause.state = 0;
		vis->buttons.status.state = 0;
	}
}

void	corewar_vis_quit(t_vis *vis)
{
	if (vis->buttons.exit.state)
		vis->buttons.exit.state = 0;
	else
		vis->buttons.exit.state = 1;
}

void	corewar_vis_reverse(t_vis *vis)
{
	if (vis->buttons.reverse.state)
		vis->buttons.reverse.state = 0;
	else
		vis->buttons.reverse.state = 1;
}
