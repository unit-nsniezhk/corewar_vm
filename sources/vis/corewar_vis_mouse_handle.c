/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_mouse_handle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:58:45 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/06 15:20:08 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

void		corewar_vis_mousewheel(t_vis *vis, SDL_Event *event)
{
	if (vis->keydown.lalt && event->wheel.y > 0)
		corewar_vis_speed(vis, 1);
	else if (vis->keydown.lalt && event->wheel.y < 0)
		corewar_vis_speed(vis, 0);
}

static void	static_mousebuttondown_left(t_vis *vis, Sint32 x, Sint32 y)
{
	if (corewar_vis_hitbox(x, y, &vis->buttons.values.button_rect))
		corewar_vis_set_press(vis, &vis->buttons.values);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.reverse.button_rect))
		corewar_vis_set_press(vis, &vis->buttons.reverse);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.exit.button_rect))
		corewar_vis_set_press(vis, &vis->buttons.exit);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.pause.button_rect))
		corewar_vis_set_press(vis, &vis->buttons.pause);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.slowdown.button_rect))
		corewar_vis_set_press(vis, &vis->buttons.slowdown);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.speedup.button_rect))
		corewar_vis_set_press(vis, &vis->buttons.speedup);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.status.button_rect))
		corewar_vis_set_press(vis, &vis->buttons.status);
	else
		corewar_vis_set_press(vis, NULL);
}

void		corewar_vis_mousebuttonup(t_vis *vis, SDL_Event *event)
{
	Sint32	x;
	Sint32	y;

	x = event->button.x;
	y = event->button.y;
	if (event->button.button == SDL_BUTTON_LEFT)
	{
		corewar_vis_set_press(vis, NULL);
		vis->keydown.mbl = 0;
		if (corewar_vis_hitbox(x, y, &vis->buttons.values.button_rect))
			corewar_vis_values(vis);
		else if (corewar_vis_hitbox(x, y, &vis->buttons.reverse.button_rect))
			corewar_vis_reverse(vis);
		else if (corewar_vis_hitbox(x, y, &vis->buttons.exit.button_rect))
			corewar_vis_quit(vis);
		else if (corewar_vis_hitbox(x, y, &vis->buttons.pause.button_rect))
			corewar_vis_run(vis);
		else if (corewar_vis_hitbox(x, y, &vis->buttons.slowdown.button_rect))
			corewar_vis_speed(vis, 0);
		else if (corewar_vis_hitbox(x, y, &vis->buttons.speedup.button_rect))
			corewar_vis_speed(vis, 1);
		else if (corewar_vis_hitbox(x, y, &vis->buttons.status.button_rect))
			corewar_vis_run(vis);
	}
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
		vis->keydown.mbl = 1;
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
	if (corewar_vis_hitbox(x, y, &vis->buttons.values.button_rect))
		corewar_vis_set_hower(vis, &vis->buttons.values);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.reverse.button_rect))
		corewar_vis_set_hower(vis, &vis->buttons.reverse);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.exit.button_rect))
		corewar_vis_set_hower(vis, &vis->buttons.exit);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.pause.button_rect))
		corewar_vis_set_hower(vis, &vis->buttons.pause);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.slowdown.button_rect))
		corewar_vis_set_hower(vis, &vis->buttons.slowdown);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.speedup.button_rect))
		corewar_vis_set_hower(vis, &vis->buttons.speedup);
	else if (corewar_vis_hitbox(x, y, &vis->buttons.status.button_rect))
		corewar_vis_set_hower(vis, &vis->buttons.status);
	else
		corewar_vis_set_hower(vis, NULL);
}
