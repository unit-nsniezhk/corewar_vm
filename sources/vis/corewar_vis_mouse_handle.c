/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vis_mouse_handle.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderevyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:58:45 by dderevyn          #+#    #+#             */
/*   Updated: 2019/05/05 23:49:40 by dderevyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vis.h"

void		corewar_vis_mousewheel(t_vis *vis, SDL_Event *event)
{
	if (vis->keydown.lalt && event->wheel.y > 0)
		corewar_vis_speedup(vis);
	else if (vis->keydown.lalt && event->wheel.y < 0)
		corewar_vis_slowdown(vis);
}

static int	static_hitbox(Sint32 x, Sint32 y, SDL_Rect *button)
{
	if (x > button->x && x < button->x + button->w
	&& y > button->y && y < button->y + button->h)
		return (1);
	return (0);
}

static void	static_set_hower(t_vis *vis, t_button *button)
{
	vis->buttons.values.hower = 0;
	vis->buttons.reverse.hower = 0;
	vis->buttons.exit.hower = 0;
	vis->buttons.pause.hower = 0;
	vis->buttons.slowdown.hower = 0;
	vis->buttons.speedup.hower = 0;
	vis->buttons.status.hower = 0;
	if (button)
		button->hower = 1;
}

static void	static_set_press(t_vis *vis, t_button *button)
{
	vis->buttons.values.press = 0;
	vis->buttons.reverse.press = 0;
	vis->buttons.exit.press = 0;
	vis->buttons.pause.press = 0;
	vis->buttons.slowdown.press = 0;
	vis->buttons.speedup.press = 0;
	vis->buttons.status.press = 0;
	if (button)
		button->press = 1;
}

static void	static_mousebuttondown_left(t_vis *vis, Sint32 x, Sint32 y)
{
	if (static_hitbox(x, y, &vis->buttons.values.button_rect))
		static_set_press(vis, &vis->buttons.values);
	else if (static_hitbox(x, y, &vis->buttons.reverse.button_rect))
		static_set_press(vis, &vis->buttons.reverse);
	else if (static_hitbox(x, y, &vis->buttons.exit.button_rect))
		static_set_press(vis, &vis->buttons.exit);
	else if (static_hitbox(x, y, &vis->buttons.pause.button_rect))
		static_set_press(vis, &vis->buttons.pause);
	else if (static_hitbox(x, y, &vis->buttons.slowdown.button_rect))
		static_set_press(vis, &vis->buttons.slowdown);
	else if (static_hitbox(x, y, &vis->buttons.speedup.button_rect))
		static_set_press(vis, &vis->buttons.speedup);
	else if (static_hitbox(x, y, &vis->buttons.status.button_rect))
		static_set_press(vis, &vis->buttons.status);
	else
		static_set_press(vis, NULL);
}

void		corewar_vis_mousebuttonup(t_vis *vis, SDL_Event *event)
{
	Sint32	x;
	Sint32	y;

	x = event->button.x;
	y = event->button.y;
	if (event->button.button == SDL_BUTTON_LEFT)
	{
		static_set_press(vis, NULL);
		vis->keydown.mbl = 0;
		if (static_hitbox(x, y, &vis->buttons.values.button_rect))
		{
			vis->mods.run = 0;
			vis->mods.values = 1;
		}
		else if (static_hitbox(x, y, &vis->buttons.reverse.button_rect))
			vis->mods.reverse = 1;
		else if (static_hitbox(x, y, &vis->buttons.exit.button_rect))
			vis->mods.quit = 1;
		else if (static_hitbox(x, y, &vis->buttons.pause.button_rect))
			vis->mods.run = 0;
		else if (static_hitbox(x, y, &vis->buttons.slowdown.button_rect))
			corewar_vis_slowdown(vis);
		else if (static_hitbox(x, y, &vis->buttons.speedup.button_rect))
			corewar_vis_speedup(vis);
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
	if (static_hitbox(x, y, &vis->buttons.values.button_rect))
		static_set_hower(vis, &vis->buttons.values);
	else if (static_hitbox(x, y, &vis->buttons.reverse.button_rect))
		static_set_hower(vis, &vis->buttons.reverse);
	else if (static_hitbox(x, y, &vis->buttons.exit.button_rect))
		static_set_hower(vis, &vis->buttons.exit);
	else if (static_hitbox(x, y, &vis->buttons.pause.button_rect))
		static_set_hower(vis, &vis->buttons.pause);
	else if (static_hitbox(x, y, &vis->buttons.slowdown.button_rect))
		static_set_hower(vis, &vis->buttons.slowdown);
	else if (static_hitbox(x, y, &vis->buttons.speedup.button_rect))
		static_set_hower(vis, &vis->buttons.speedup);
	else if (static_hitbox(x, y, &vis->buttons.status.button_rect))
		static_set_hower(vis, &vis->buttons.status);
	else
		static_set_hower(vis, NULL);
}
