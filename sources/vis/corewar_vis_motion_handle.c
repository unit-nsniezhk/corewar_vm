/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_motion_handle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:21:54 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/09 19:45:12 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

void	corewar_vis_process_shown(Sint32 x, Sint32 y, t_carriage *carr_tmp)
{
	while (carr_tmp)
	{
		if (x > carr_tmp->box.x && x < carr_tmp->box.x + carr_tmp->box.w
		&& y > carr_tmp->box.y && y < carr_tmp->box.y + carr_tmp->box.h)
			carr_tmp->shown = true;
		else
			carr_tmp->shown = false;
		carr_tmp = carr_tmp->next;
	}
}

void	corewar_vis_mousemotion(t_vis *vis, SDL_Event *event)
{
	vis->m_x = event->motion.x;
	vis->m_y = event->motion.y;
	if (vis->keydown.mbl)
		corewar_mousebuttondown_left(vis, event->motion.x, event->motion.y);
	if (corewar_vis_hitbox(vis->m_x, vis->m_y, &vis->buttons.values.bg))
		corewar_vis_set_hower(vis, &vis->buttons.values);
	else if (corewar_vis_hitbox(vis->m_x, vis->m_y, &vis->buttons.reverse.bg))
		corewar_vis_set_hower(vis, &vis->buttons.reverse);
	else if (corewar_vis_hitbox(vis->m_x, vis->m_y, &vis->buttons.exit.bg))
		corewar_vis_set_hower(vis, &vis->buttons.exit);
	else if (corewar_vis_hitbox(vis->m_x, vis->m_y, &vis->buttons.run.bg))
		corewar_vis_set_hower(vis, &vis->buttons.run);
	else if (corewar_vis_hitbox(vis->m_x, vis->m_y, &vis->buttons.slowdown.bg))
		corewar_vis_set_hower(vis, &vis->buttons.slowdown);
	else if (corewar_vis_hitbox(vis->m_x, vis->m_y, &vis->buttons.speedup.bg))
		corewar_vis_set_hower(vis, &vis->buttons.speedup);
	else if (corewar_vis_hitbox(vis->m_x, vis->m_y, &vis->buttons.status.bg))
		corewar_vis_set_hower(vis, &vis->buttons.status);
	else if (corewar_vis_hitbox(vis->m_x, vis->m_y, &vis->buttons.nxt.bg))
		corewar_vis_set_hower(vis, &vis->buttons.nxt);
	else
		corewar_vis_set_hower(vis, NULL);
}
