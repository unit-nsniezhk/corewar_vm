/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_mods.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:40:21 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 21:46:33 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

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
	if (vis->buttons.run.active)
	{
		vis->buttons.run.active = false;
		vis->buttons.status.active = false;
		Mix_PauseMusic();
	}
	else
	{
		vis->buttons.run.active = true;
		vis->buttons.status.active = true;
		vis->buttons.values.active = false;
		Mix_ResumeMusic();
	}
}

void	corewar_vis_values(t_vis *vis)
{
	if (vis->buttons.values.active)
		vis->buttons.values.active = false;
	else
	{
		vis->buttons.values.active = true;
		vis->buttons.run.active = false;
		vis->buttons.status.active = false;
		Mix_PauseMusic();
	}
}

void	corewar_vis_quit(t_vis *vis)
{
	if (vis->buttons.exit.active)
		vis->buttons.exit.active = false;
	else
		vis->buttons.exit.active = true;
}

void	corewar_vis_reverse(t_vis *vis)
{
	if (vis->buttons.reverse.active)
		vis->buttons.reverse.active = false;
	else
		vis->buttons.reverse.active = true;
}
