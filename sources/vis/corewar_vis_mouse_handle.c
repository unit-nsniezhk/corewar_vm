/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_mouse_handle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:58:45 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/08 20:33:27 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

static void	static_mousebuttonup_left(t_vis *vis, Sint32 x, Sint32 y)
{
	corewar_vis_set_press(vis, NULL);
	if (corewar_vis_hitbox(x, y, &vis->buttons.values.bg))
		corewar_vis_values(vis);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.reverse.bg))
		corewar_vis_reverse(vis);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.exit.bg))
		corewar_vis_quit(vis);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.pause.bg))
		corewar_vis_run(vis);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.slowdown.bg))
		corewar_vis_speed(vis, false);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.speedup.bg))
		corewar_vis_speed(vis, true);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.status.bg))
		corewar_vis_run(vis);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.nxt.bg))
		corewar_vis_nxt(vis);
}

void		corewar_vis_mousebuttonup(t_vis *vis, SDL_Event *event)
{
	Sint32	x;
	Sint32	y;

	x = event->button.x;
	y = event->button.y;
	if (event->button.button == SDL_BUTTON_LEFT)
	{
		static_mousebuttonup_left(vis, x, y);
		vis->keydown.mbl = false;
	}
}

static void	static_mousebuttondown_left(t_vis *vis, Sint32 x, Sint32 y)
{
	if (corewar_vis_hitbox(x, y, &vis->buttons.values.bg))
		corewar_vis_set_press(vis, &vis->buttons.values);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.reverse.bg))
		corewar_vis_set_press(vis, &vis->buttons.reverse);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.exit.bg))
		corewar_vis_set_press(vis, &vis->buttons.exit);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.pause.bg))
		corewar_vis_set_press(vis, &vis->buttons.pause);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.slowdown.bg))
		corewar_vis_set_press(vis, &vis->buttons.slowdown);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.speedup.bg))
		corewar_vis_set_press(vis, &vis->buttons.speedup);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.status.bg))
		corewar_vis_set_press(vis, &vis->buttons.status);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.nxt.bg))
		corewar_vis_set_press(vis, &vis->buttons.nxt);
	else
		corewar_vis_set_press(vis, NULL);
}

void		corewar_vis_mousebuttondown(t_vis *vis, SDL_Event *event)
{
	Sint32	x;
	Sint32	y;

	x = event->button.x;
	y = event->button.y;
	if (event->button.button == SDL_BUTTON_LEFT)
	{
		static_mousebuttondown_left(vis, x, y);
		vis->keydown.mbl = true;
	}
}

void		corewar_vis_mousemotion(t_vis *vis, SDL_Event *event)
{
	Sint32	x;
	Sint32	y;

	x = event->motion.x;
	y = event->motion.y;
	if (vis->keydown.mbl)
		static_mousebuttondown_left(vis, event->motion.x, event->motion.y);
	if (corewar_vis_hitbox(x, y, &vis->buttons.values.bg))
		corewar_vis_set_hower(vis, &vis->buttons.values);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.reverse.bg))
		corewar_vis_set_hower(vis, &vis->buttons.reverse);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.exit.bg))
		corewar_vis_set_hower(vis, &vis->buttons.exit);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.pause.bg))
		corewar_vis_set_hower(vis, &vis->buttons.pause);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.slowdown.bg))
		corewar_vis_set_hower(vis, &vis->buttons.slowdown);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.speedup.bg))
		corewar_vis_set_hower(vis, &vis->buttons.speedup);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.status.bg))
		corewar_vis_set_hower(vis, &vis->buttons.status);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.nxt.bg))
		corewar_vis_set_hower(vis, &vis->buttons.nxt);
	else
		corewar_vis_set_hower(vis, NULL);
}
